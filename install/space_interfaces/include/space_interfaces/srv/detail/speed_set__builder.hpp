// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/SpeedSet.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__BUILDER_HPP_

#include "space_interfaces/srv/detail/speed_set__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_SpeedSet_Request_speed
{
public:
  Init_SpeedSet_Request_speed()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::SpeedSet_Request speed(::space_interfaces::srv::SpeedSet_Request::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::SpeedSet_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::SpeedSet_Request>()
{
  return space_interfaces::srv::builder::Init_SpeedSet_Request_speed();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_SpeedSet_Response_success
{
public:
  Init_SpeedSet_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::SpeedSet_Response success(::space_interfaces::srv::SpeedSet_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::SpeedSet_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::SpeedSet_Response>()
{
  return space_interfaces::srv::builder::Init_SpeedSet_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__BUILDER_HPP_
