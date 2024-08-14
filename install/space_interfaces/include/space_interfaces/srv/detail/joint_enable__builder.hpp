// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/JointEnable.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__BUILDER_HPP_

#include "space_interfaces/srv/detail/joint_enable__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointEnable_Request_data
{
public:
  explicit Init_JointEnable_Request_data(::space_interfaces::srv::JointEnable_Request & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::JointEnable_Request data(::space_interfaces::srv::JointEnable_Request::_data_type arg)
  {
    msg_.data = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::JointEnable_Request msg_;
};

class Init_JointEnable_Request_joint
{
public:
  Init_JointEnable_Request_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointEnable_Request_data joint(::space_interfaces::srv::JointEnable_Request::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_JointEnable_Request_data(msg_);
  }

private:
  ::space_interfaces::srv::JointEnable_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::JointEnable_Request>()
{
  return space_interfaces::srv::builder::Init_JointEnable_Request_joint();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_JointEnable_Response_message
{
public:
  explicit Init_JointEnable_Response_message(::space_interfaces::srv::JointEnable_Response & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::JointEnable_Response message(::space_interfaces::srv::JointEnable_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::JointEnable_Response msg_;
};

class Init_JointEnable_Response_success
{
public:
  explicit Init_JointEnable_Response_success(::space_interfaces::srv::JointEnable_Response & msg)
  : msg_(msg)
  {}
  Init_JointEnable_Response_message success(::space_interfaces::srv::JointEnable_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_JointEnable_Response_message(msg_);
  }

private:
  ::space_interfaces::srv::JointEnable_Response msg_;
};

class Init_JointEnable_Response_joint
{
public:
  Init_JointEnable_Response_joint()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JointEnable_Response_success joint(::space_interfaces::srv::JointEnable_Response::_joint_type arg)
  {
    msg_.joint = std::move(arg);
    return Init_JointEnable_Response_success(msg_);
  }

private:
  ::space_interfaces::srv::JointEnable_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::JointEnable_Response>()
{
  return space_interfaces::srv::builder::Init_JointEnable_Response_joint();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__BUILDER_HPP_
