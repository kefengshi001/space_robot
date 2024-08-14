// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/Connection.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CONNECTION__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CONNECTION__BUILDER_HPP_

#include "space_interfaces/srv/detail/connection__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_Connection_Request_connect
{
public:
  Init_Connection_Request_connect()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::Connection_Request connect(::space_interfaces::srv::Connection_Request::_connect_type arg)
  {
    msg_.connect = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::Connection_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::Connection_Request>()
{
  return space_interfaces::srv::builder::Init_Connection_Request_connect();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_Connection_Response_success
{
public:
  Init_Connection_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::space_interfaces::srv::Connection_Response success(::space_interfaces::srv::Connection_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::Connection_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::Connection_Response>()
{
  return space_interfaces::srv::builder::Init_Connection_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__CONNECTION__BUILDER_HPP_
