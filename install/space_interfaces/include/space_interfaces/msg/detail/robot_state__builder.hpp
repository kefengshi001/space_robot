// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
#define SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_

#include "space_interfaces/msg/detail/robot_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace msg
{

namespace builder
{

class Init_RobotState_orientation
{
public:
  explicit Init_RobotState_orientation(::space_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  ::space_interfaces::msg::RobotState orientation(::space_interfaces::msg::RobotState::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::msg::RobotState msg_;
};

class Init_RobotState_position
{
public:
  explicit Init_RobotState_position(::space_interfaces::msg::RobotState & msg)
  : msg_(msg)
  {}
  Init_RobotState_orientation position(::space_interfaces::msg::RobotState::_position_type arg)
  {
    msg_.position = std::move(arg);
    return Init_RobotState_orientation(msg_);
  }

private:
  ::space_interfaces::msg::RobotState msg_;
};

class Init_RobotState_jointposition
{
public:
  Init_RobotState_jointposition()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_RobotState_position jointposition(::space_interfaces::msg::RobotState::_jointposition_type arg)
  {
    msg_.jointposition = std::move(arg);
    return Init_RobotState_position(msg_);
  }

private:
  ::space_interfaces::msg::RobotState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::msg::RobotState>()
{
  return space_interfaces::msg::builder::Init_RobotState_jointposition();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__BUILDER_HPP_
