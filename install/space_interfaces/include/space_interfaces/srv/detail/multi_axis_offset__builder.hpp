// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/MultiAxisOffset.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS_OFFSET__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS_OFFSET__BUILDER_HPP_

#include "space_interfaces/srv/detail/multi_axis_offset__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_MultiAxisOffset_Request_offsetangle
{
public:
  Init_MultiAxisOffset_Request_offsetangle()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::MultiAxisOffset_Request offsetangle(::space_interfaces::srv::MultiAxisOffset_Request::_offsetangle_type arg)
  {
    msg_.offsetangle = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxisOffset_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::MultiAxisOffset_Request>()
{
  return space_interfaces::srv::builder::Init_MultiAxisOffset_Request_offsetangle();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_MultiAxisOffset_Response_message
{
public:
  explicit Init_MultiAxisOffset_Response_message(::space_interfaces::srv::MultiAxisOffset_Response & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::MultiAxisOffset_Response message(::space_interfaces::srv::MultiAxisOffset_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxisOffset_Response msg_;
};

class Init_MultiAxisOffset_Response_success
{
public:
  Init_MultiAxisOffset_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultiAxisOffset_Response_message success(::space_interfaces::srv::MultiAxisOffset_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_MultiAxisOffset_Response_message(msg_);
  }

private:
  ::space_interfaces::srv::MultiAxisOffset_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::MultiAxisOffset_Response>()
{
  return space_interfaces::srv::builder::Init_MultiAxisOffset_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS_OFFSET__BUILDER_HPP_
