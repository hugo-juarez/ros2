#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

using namespace std::chrono_literals;
using example_interfaces::msg::String;

class RobotNews : public rclcpp::Node
{
public:
    RobotNews() : Node{"robot_news"}, name_{"R2D2"}
    {
        timer_ = this->create_wall_timer(1s, [this](){
            this->publish_news();
        });
        publisher_ = this->create_publisher<String>("robot_news", 10);
        RCLCPP_INFO(this->get_logger(), "Robot News Started!");
    }

    void publish_news() {
        String msg = String();
        msg.data = "Hello, this is " + name_ + " from Robot News Station";
        publisher_->publish(msg);
    }

private:
    rclcpp::Publisher<String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::string name_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<RobotNews>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}