#include <rclcpp/rclcpp.hpp>

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node{"my_first_node"}
    {
        timer_ = this->create_wall_timer(std::chrono::milliseconds(500), [this](){
            this->timer_callback();
        });
        RCLCPP_INFO(this->get_logger(), "My First Node Started!");
    }

    void timer_callback() {
        RCLCPP_INFO(this->get_logger(), "Hello %d", counter_++);
    }

private:
    rclcpp::TimerBase::SharedPtr timer_;
    int counter_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<MyNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}