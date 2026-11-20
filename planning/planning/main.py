# ROS Libraries
from std_srvs.srv import Trigger
import sys
import copy
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from rclpy.duration import Duration
from rclpy.time import Time
from control_msgs.action import FollowJointTrajectory
from controller_manager_msgs.srv import SwitchController
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Float32
from moveit_msgs.msg import RobotTrajectory
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from sensor_msgs.msg import JointState
from tf2_ros import Buffer, TransformListener
from scipy.spatial.transform import Rotation as R
import numpy as np

from planning.ik import IKPlanner

TAPE_SETTLE_SEC = 1.0  # wait this long after getting back to the start pose before trusting /tape_pose

# How far below wrist_3_link the fingertips are. Measure this on your gripper!
# The IK targets are for wrist_3_link, so add this to where you want the fingertips to be.
GRIPPER_LENGTH = 0.14
PRE_GRASP_CLEARANCE = 0.1  # how far above the cube the fingertips start
TABLE_CLEARANCE = 0.01  # never bring the fingertips (or the held cube) closer than this to the table

BLOCK_HEIGHT = 0.025
BLOCK_WIDTH = 0.04
BLOCK_LENGTH = 0.119
PUSH_AMT = 0.06
PULL_AMT = 0.1

class UR7e_Movement(Node):
    def __init__(self):
        super().__init__('cube_grasp')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.joint_state_sub = self.create_subscription(JointState, '/joint_states', self.joint_state_callback, 1)
        # self.command_sub = self.create_subscription(Command, '/command', self.command_callback, 1)

        self.exec_ac = ActionClient(
            self, FollowJointTrajectory,
            '/scaled_joint_trajectory_controller/follow_joint_trajectory'
        )

        self.gripper_cli = self.create_client(Trigger, '/toggle_gripper')
        self.switch_cli = self.create_client(SwitchController, '/controller_manager/switch_controller')

        self.tower_pos = None
        self.tower_rot = None
        self.block_level = None
        self.block_index = None
        
        self.joint_state = None
        self.start_joints = None  # where you free drove the robot to, recorded on startup

        self.ik_planner = IKPlanner()

        self.job_queue = [] # Entries should be of type either JointState, String('toggle_grip') or String('find_tape')

        # after free driving, the trajectory controller might not be the active one anymore
        self._switch_to_trajectory_controller()

    def joint_state_callback(self, msg: JointState):
        self.joint_state = msg
        if self.start_joints is None:
            self.start_joints = copy.deepcopy(msg)
            self.get_logger().info('Recorded the start pose, we will come back here to look for the tape')

    def command_callback(self, command):
        current_command = command.command
        if current_command == "pull":
            self.pull_callback(command.tower_pose, command.block_level, command.block_index)

    def pull_callback(self, tower_pose, block_level, block_index):
        if self.tower_pos is not None or self.tower_rot is not None:
            return

        self.tower_pos = tower_pose.transform.translation
        self.tower_rot = tower_pose.transform.rotation
        self.block_level = block_level
        self.block_index = block_index
        # /cube_pose is the middle of the cube, and /cube_height is how tall it is
        x, y, z = self.tower_pos.x, self.tower_pos.y, self.tower_pos.z
        block_x = x - PUSH_AMT
        block_y = (y - 1.5 * BLOCK_WIDTH) + (self.block_index - 0.5) * BLOCK_WIDTH
        block_z = z + (self.block_level - 0.5) * BLOCK_HEIGHT
        self.get_logger().info(f'Tower at ({x:.3f}, {y:.3f}, {z:.3f})')

        # -----------------------------------------------------------
        # TODO: In the following section you will add joint angles to the job queue.
        # Entries of the job queue should be of type either JointState, String('toggle_grip') or String('find_tape')
        # Think about you will leverage the IK planner to get joint configurations for the cube grasping task.
        # To understand how the queue works, refer to the execute_jobs() function below.
        # -----------------------------------------------------------
        # 1) Move to Pre-Grasp Position (gripper above the cube)
        '''
        The fingertips should start PRE_GRASP_CLEARANCE above the top of the cube.
        Remember the IK target is wrist_3_link, which is GRIPPER_LENGTH above the fingertips.
        '''

        wrist_3_pose = self.tf_buffer.lookup_transform("base_link", "wrist_3_link", Time(), timeout=Duration(seconds=0.5))
        current_z = wrist_3_pose.transform.translation.z
        pre_grasp_ik_tall = self.ik_planner.compute_ik(self.joint_state, block_x, block_y, current_z, 0.0, 0.7071, -0.7071, 0.0)
        self.job_queue.append(pre_grasp_ik_tall)

        true_z = GRIPPER_LENGTH + PRE_GRASP_CLEARANCE + block_z
        pre_grasp_ik = self.ik_planner.compute_ik(self.joint_state, block_x, block_y, true_z)
        self.job_queue.append(pre_grasp_ik)

        # 2) Move to Grasp Position (lower the gripper to the cube)
        '''
        Put the fingertips at the middle of the cube (half its height), but never closer
        than TABLE_CLEARANCE to the table. Save how far above the bottom of the cube the
        fingertips are in self.grasp_height, you'll need it to put the cube down.
        '''
        grasp_height = block_z + GRIPPER_LENGTH + 0.01
        grasp_ik = self.ik_planner.compute_ik(self.joint_state, block_x, block_y, grasp_height)
        self.job_queue.append(grasp_ik)

        # 3) Close the gripper. See job_queue entries defined in init above for how to add this action.
        self.job_queue.append('toggle_grip')

        # 4) Move back to Pre-Grasp Position
        pull_x = block_x + PULL_AMT
        post_grasp_ik = self.ik_planner.compute_ik(self.joint_state, pull_x, block_y, grasp_height)
        self.job_queue.append(post_grasp_ik)

        self.job_queue.append(pre_grasp_ik_tall)

        # 5) Go back to the start pose (self.start_joints) so the camera can see the table again
        self.job_queue.append(self.start_joints)

        self.execute_jobs()


    def execute_jobs(self):
        if not self.job_queue:
            self.get_logger().info("All jobs completed.")
            rclpy.shutdown()
            return

        self.get_logger().info(f"Executing job queue, {len(self.job_queue)} jobs remaining.")
        next_job = self.job_queue.pop(0)

        if isinstance(next_job, JointState):

            traj = self.ik_planner.plan_to_joints(next_job)
            if traj is None:
                self.get_logger().error("Failed to plan to position")
                return

            self.get_logger().info("Planned to position")

            self._execute_joint_trajectory(traj.joint_trajectory)
        elif next_job == 'toggle_grip':
            self.get_logger().info("Toggling gripper")
            self._toggle_gripper()
        else:
            self.get_logger().error("Unknown job type.")
            self.execute_jobs()  # Proceed to next job

    def _switch_to_trajectory_controller(self):
        if not self.switch_cli.wait_for_service(timeout_sec=5.0):
            self.get_logger().warn('No controller_manager, assuming the trajectory controller is already active')
            return
        req = SwitchController.Request()
        req.activate_controllers = ['scaled_joint_trajectory_controller']
        req.deactivate_controllers = ['freedrive_mode_controller', 'forward_position_controller',
                                      'forward_velocity_controller']
        req.strictness = SwitchController.Request.BEST_EFFORT
        req.activate_asap = True
        future = self.switch_cli.call_async(req)
        rclpy.spin_until_future_complete(self, future, timeout_sec=5.0)
        if future.result() is None or not future.result().ok:
            self.get_logger().warn('Could not switch to scaled_joint_trajectory_controller')

    def _toggle_gripper(self):
        if not self.gripper_cli.wait_for_service(timeout_sec=5.0):
            self.get_logger().error('Gripper service not available')
            rclpy.shutdown()
            return

        req = Trigger.Request()
        future = self.gripper_cli.call_async(req)
        # wait for 2 seconds
        rclpy.spin_until_future_complete(self, future, timeout_sec=2.0)

        self.get_logger().info('Gripper toggled.')
        self.execute_jobs()  # Proceed to next job


    def _execute_joint_trajectory(self, joint_traj):
        self.get_logger().info('Waiting for controller action server...')
        self.exec_ac.wait_for_server()

        goal = FollowJointTrajectory.Goal()
        goal.trajectory = joint_traj

        self.get_logger().info('Sending trajectory to controller...')
        send_future = self.exec_ac.send_goal_async(goal)
        print(send_future)
        send_future.add_done_callback(self._on_goal_sent)

    def _on_goal_sent(self, future):
        goal_handle = future.result()
        if not goal_handle.accepted:
            self.get_logger().error('bonk')
            rclpy.shutdown()
            return

        self.get_logger().info('Executing...')
        result_future = goal_handle.get_result_async()
        result_future.add_done_callback(self._on_exec_done)

    def _on_exec_done(self, future):
        try:
            result = future.result().result
            self.get_logger().info('Execution complete.')
            self.execute_jobs()  # Proceed to next job
        except Exception as e:
            self.get_logger().error(f'Execution failed: {e}')


# def main(args=None):
#     rclpy.init(args=args)
#     node = UR7e_Movement()
#     rclpy.spin(node)
#     node.destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = UR7e_Movement()

    # Wait until joint states are received
    while rclpy.ok() and node.joint_state is None:
        rclpy.spin_once(node, timeout_sec=0.1)

    # Create dummy tower pose
    tower_pose = node.tf_buffer.lookup_transform("base_link", "jenga", Time(), timeout=Duration(seconds=0.5))

    # Test parameters
    block_level = 6
    block_index = 2

    node.get_logger().info("Testing pull_callback...")

    node.pull_callback(tower_pose, block_level, block_index)

    # Keep node alive while asynchronous jobs execute
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == '__main__':
    main()
