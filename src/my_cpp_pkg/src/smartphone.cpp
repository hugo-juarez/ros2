#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/msg/string.hpp>

using example_interfaces::msg::String;

class SmartPhone : public rclcpp::Node
{
public:
    SmartPhone() : Node{"smartphone"}
    {
        subscriber_ = this->create_subscription<String>("robot_news", 10, [this](String::SharedPtr msg){
            this->callback_robot_news(msg);
        });
        RCLCPP_INFO(this->get_logger(), "Smartphone Node Started!");
    }

    void callback_robot_news(String::SharedPtr msg){
        RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
    }

private:
    rclcpp::Subscription<String>::SharedPtr subscriber_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SmartPhone>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}