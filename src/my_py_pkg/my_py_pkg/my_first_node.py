#/usr/bin/env python3
import rclpy
from rclpy.node import Node

class MyNode(Node):
    def __init__(self):
        super().__init__("my_first_node")
        self.count_ = 0
        self.create_timer(1, self.timer_callback)
        self.get_logger().info("My First Node Started!")

    def timer_callback(self):
        self.get_logger().info("Hello " + str(self.count_))
        self.count_ += 1


def main(args=None):
    rclpy.init()
    node = MyNode()
    rclpy.spin(node)
    rclpy.shutdown()

if __name__ == "__main__":
    main()