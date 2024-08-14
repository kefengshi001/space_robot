// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__BUILDER_HPP_
#define SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__BUILDER_HPP_

#include "space_interfaces/msg/detail/joint_jogging_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace msg
{

namespace builder
{

class Init_JointJoggingMsg_signal
{
public:
  explicit Init_JointJoggingMsg_signal(::space_interfaces::msg::JointJoggingMsg & msg)
  : msg_(msg)
  {}
  ::space_interfaces::msg::JointJoggingMsg signal(::space_interfaces::msg::JointJoggingMsg::_signal_type arg)
  {
    msg_.signal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::msg::JointJoggingMsg msg_;
};

class Init_JointJoggingMsg_run
{
public:
  explicit Init_JointJoggingMsg_run(::space_interfaces::msg::JointJoggingMsg & msg)
  : msg_(msg)
  {}
  Init_JointJoggingMsg_signal run(::space_interfaces::msg::JointJoggingMsg::_run_type arg)
  {
    msg_.run = std::move(arg);
    return Init_JointJoggingMsg_signal(msg_);
  }

private:
  ::space_interfaces::msg::JointJoggingMsg msg_;
};

class Init_JointJoggingMsg_joint
{
public:
  Init_JointJoggingMsg_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointJoggingMsg_run joint(::space_interfaces::msg::JointJoggingMsg::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_JointJoggingMsg_run(msg_);
  }

private:
  ::space_interfaces::msg::JointJoggingMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::msg::JointJoggingMsg>()
{
  return space_interfaces::msg::builder::Init_JointJoggingMsg_joint();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__BUILDER_HPP_
