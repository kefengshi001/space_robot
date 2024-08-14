// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__SWITCH__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__SWITCH__BUILDER_HPP_

#include "space_interfaces/srv/detail/switch__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_Switch_Request_adapter_status
{
public:
  explicit Init_Switch_Request_adapter_status(::space_interfaces::srv::Switch_Request & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::Switch_Request adapter_status(::space_interfaces::srv::Switch_Request::_adapter_status_type arg)
  {
    msg_.adapter_status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::Switch_Request msg_;
};

class Init_Switch_Request_switch_enable
{
public:
  Init_Switch_Request_switch_enable()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Switch_Request_adapter_status switch_enable(::space_interfaces::srv::Switch_Request::_switch_enable_type arg)
  {
    msg_.switch_enable = std::move(arg);
    return Init_Switch_Request_adapter_status(msg_);
  }

private:
  ::space_interfaces::srv::Switch_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::Switch_Request>()
{
  return space_interfaces::srv::builder::Init_Switch_Request_switch_enable();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_Switch_Response_success
{
public:
  Init_Switch_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::Switch_Response success(::space_interfaces::srv::Switch_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::Switch_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::Switch_Response>()
{
  return space_interfaces::srv::builder::Init_Switch_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__SWITCH__BUILDER_HPP_
