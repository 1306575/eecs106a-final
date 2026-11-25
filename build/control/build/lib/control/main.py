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
from command_msgs.srv import Command
import numpy as np

from planning.ik import IKPlanner

# How far below wrist_3_link the fingertips are. Measure this on your gripper!
# The IK targets are for wrist_3_link, so add this to where you want the fingertips to be.
GRIPPER_LENGTH = 0.14
PRE_GRASP_CLEARANCE = 0.1  # how far above the cube the fingertips start
TABLE_CLEARANCE = 0.01  # never bring the fingertips (or the held cube) closer than this to the table

BLOCK_HEIGHT = 0.025
BLOCK_WIDTH = 0.04
BLOCK_LENGTH = 0.119
PULL_FROM = 0.11
PULL_AMT = 0.1

class Command_Node(Node):
    def __init__(self):
        super().__init__('command')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        self.service_client = self.create_client(Command, 'jenga_command')
        while not self.service_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('service not available, waiting again...')
        self.request = Command.Request()

        self.current_state = None

    def send_request(self, command_type, block_level, block_index):
        self.request.command = command_type
        self.request.block_level = block_level
        self.request.block_index = block_index
        
        self.future = self.service_client.call_async(self.request)
        rclpy.spin_until_future_complete(self, self.future)
        return self.future.result()

# def main(args=None):
#     rclpy.init(args=args)
#     node = UR7e_Movement()
#     rclpy.spin(node)
#     node.destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = Command_Node()

    response = node.send_request("pull", 3, 3)

    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
