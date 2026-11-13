#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import TransformStamped
from tf2_ros import StaticTransformBroadcaster
from scipy.spatial.transform import Rotation as R
import numpy as np

class StaticTransformPublisher(Node):
    def __init__(self):
        super().__init__('tf_node')
        self.br = StaticTransformBroadcaster(self)

        # Homogeneous transform G wrist_3_link -> camera_color_optical_frame
        G1 = np.array([[1, 0, 0, -0.025],
                      [0, 1, 0, 0.13],
                      [0, 0, 1, 0.0],
                      [0, 0, 0, 1.0]
        ])

        G2 = np.array([[1, 0, 0, 0.15],
                      [0, 1, 0, 0],
                      [0, 0, 1, 0],
                      [0, 0, 0, 1.0]
        ])

        
        # Create TransformStamped
        self.transform_camera = TransformStamped()
        self.transform_jenga = TransformStamped()

        rotation_matrix_camera = G1[:3, :3]
        translation_camera = G1[:3, 3]

        q1 = R.from_matrix(rotation_matrix_camera).as_quat()

        self.transform_camera.header.frame_id = 'wrist_3_link'
        self.transform_camera.child_frame_id = 'camera_link'

        self.transform_camera.transform.translation.x = float(translation_camera[0])
        self.transform_camera.transform.translation.y = float(translation_camera[1])
        self.transform_camera.transform.translation.z = float(translation_camera[2])

        self.transform_camera.transform.rotation.x = float(q1[0])
        self.transform_camera.transform.rotation.y = float(q1[1])
        self.transform_camera.transform.rotation.z = float(q1[2])
        self.transform_camera.transform.rotation.w = float(q1[3])

        rotation_matrix_goal = G2[:3, :3]
        translation_goal = G2[:3, 3]

        q2 = R.from_matrix(rotation_matrix_goal).as_quat()

        self.transform_jenga.header.frame_id = "ar_marker_1"          #TODO: set this to whichever small tag you're using
        self.transform_jenga.child_frame_id = 'jenga'

        self.transform_jenga.transform.translation.x = float(translation_goal[0])
        self.transform_jenga.transform.translation.y = float(translation_goal[1])
        self.transform_jenga.transform.translation.z = float(translation_goal[2])

        self.transform_jenga.transform.rotation.x = float(q2[0])
        self.transform_jenga.transform.rotation.y = float(q2[1])
        self.transform_jenga.transform.rotation.z = float(q2[2])
        self.transform_jenga.transform.rotation.w = float(q2[3])

        self.get_logger().info(f"Broadcasting camera mount transform:\n{G1}\nQuaternion: {q1}")
        self.get_logger().info(f"Broadcasting jenga pose transform:\n{G2}\nQuaternion: {q2}")

        self.timer = self.create_timer(0.05, self.broadcast_tf)

    def broadcast_tf(self):
        self.transform_camera.header.stamp = self.get_clock().now().to_msg()
        self.transform_jenga.header.stamp = self.get_clock().now().to_msg()
        self.br.sendTransform([self.transform_camera, self.transform_jenga])
        #self.br.sendTransform([self.transform_jenga])


def main():
    rclpy.init()
    node = StaticTransformPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
