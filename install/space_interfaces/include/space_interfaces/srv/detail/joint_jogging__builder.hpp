// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/JointJogging.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__BUILDER_HPP_

#include "space_interfaces/srv/detail/joint_jogging__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointJogging_Request_signal
{
public:
  explicit Init_JointJogging_Request_signal(::space_interfaces::srv::JointJogging_Request & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::JointJogging_Request signal(::space_interfaces::srv::JointJogging_Request::_signal_type arg)
  {
    msg_.signal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::JointJogging_Request msg_;
};

class Init_JointJogging_Request_run
{
public:
  explicit Init_JointJogging_Request_run(::space_interfaces::srv::JointJogging_Request & msg)
  : msg_(msg)
  {}
  Init_JointJogging_Request_signal run(::space_interfaces::srv::JointJogging_Request::_run_type arg)
  {
    msg_.run = std::move(arg);
    return Init_JointJogging_Request_signal(msg_);
  }

private:
  ::space_interfaces::srv::JointJogging_Request msg_;
};

class Init_JointJogging_Request_joint
{
public:
  Init_JointJogging_Request_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointJogging_Request_run joint(::space_interfaces::srv::JointJogging_Request::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_JointJogging_Request_run(msg_);
  }

private:
  ::space_interfaces::srv::JointJogging_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::JointJogging_Request>()
{
  return space_interfaces::srv::builder::Init_JointJogging_Request_joint();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointJogging_Response_message
{
public:
  explicit Init_JointJogging_Response_message(::space_interfaces::srv::JointJogging_Response & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::JointJogging_Response message(::space_interfaces::srv::JointJogging_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::JointJogging_Response msg_;
};

class Init_JointJogging_Response_success
{
public:
  Init_JointJogging_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointJogging_Response_message success(::space_interfaces::srv::JointJogging_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_JointJogging_Response_message(msg_);
  }

private:
  ::space_interfaces::srv::JointJogging_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::JointJogging_Response>()
{
  return space_interfaces::srv::builder::Init_JointJogging_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__BUILDER_HPP_
