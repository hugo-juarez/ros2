#/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String

class RobotNewsNode(Node):
    def __init__(self):
        super().__init__("robot_news")
        self.name_ = "C3P0"
        self.timer_ = self.create_timer(1, self.publish_news)
        self.publisher_ = self.create_publisher(String, "robot_news", 10)
        self.get_logger().info("Robot News Started!")

    def publish_news(self):
        msg = String()
        msg.data = "Hello this is " + self.name_ + " from Robot News Station."
        self.publisher_.publish(msg)


def main(args=None):
    rclpy.init()
    node = RobotNewsNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()