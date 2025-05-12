#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"

class NavigatorNode : public rclcpp::Node {
public:
  NavigatorNode() : Node("navigator_node") {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
      std::bind(&NavigatorNode::navigate, this));
  }

private:
  void navigate() {
    geometry_msgs::msg::Twist cmd;
    cmd.linear.x = 0.2;  // Move forward
    cmd.angular.z = 0.0; // No turn
    publisher_->publish(cmd);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[]) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<NavigatorNode>());
  rclcpp::shutdown();
  return 0;
}
