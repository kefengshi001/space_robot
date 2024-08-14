// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/MultiAxis.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__BUILDER_HPP_

#include "space_interfaces/srv/detail/multi_axis__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_MultiAxis_Request_goalangle
{
public:
  Init_MultiAxis_Request_goalangle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::MultiAxis_Request goalangle(::space_interfaces::srv::MultiAxis_Request::_goalangle_type arg)
  {
    msg_.goalangle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxis_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::MultiAxis_Request>()
{
  return space_interfaces::srv::builder::Init_MultiAxis_Request_goalangle();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_MultiAxis_Response_message
{
public:
  explicit Init_MultiAxis_Response_message(::space_interfaces::srv::MultiAxis_Response & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::MultiAxis_Response message(::space_interfaces::srv::MultiAxis_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxis_Response msg_;
};

class Init_MultiAxis_Response_success
{
public:
  Init_MultiAxis_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiAxis_Response_message success(::space_interfaces::srv::MultiAxis_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MultiAxis_Response_message(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxis_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::MultiAxis_Response>()
{
  return space_interfaces::srv::builder::Init_MultiAxis_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__BUILDER_HPP_
