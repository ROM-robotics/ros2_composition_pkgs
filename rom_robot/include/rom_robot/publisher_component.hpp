// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ROM_ROBOT__PUBLISHER_COMPONENT_HPP_
#define ROM_ROBOT__PUBLISHER_COMPONENT_HPP_

#include "rom_robot/visibility_control.h"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

namespace rom_robot
{

class Mypublisher : public rclcpp::Node
{
public:
  ROM_ROBOT_PUBLIC
  explicit Mypublisher(const rclcpp::NodeOptions & options);

protected:
  void on_timer();

private:
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;
};

}  // namespace rom_robot

#endif  // ROM_ROBOT__PUBLISHER_COMPONENT_HPP_
