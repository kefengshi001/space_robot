// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from space_interfaces:srv/CartesianMovement.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__BUILDER_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__BUILDER_HPP_

#include "space_interfaces/srv/detail/cartesian_movement__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_CartesianMovement_Request_signal
{
public:
  explicit Init_CartesianMovement_Request_signal(::space_interfaces::srv::CartesianMovement_Request & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::CartesianMovement_Request signal(::space_interfaces::srv::CartesianMovement_Request::_signal_type arg)
  {
    msg_.signal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::CartesianMovement_Request msg_;
};

class Init_CartesianMovement_Request_goalorientation
{
public:
  explicit Init_CartesianMovement_Request_goalorientation(::space_interfaces::srv::CartesianMovement_Request & msg)
  : msg_(msg)
  {}
  Init_CartesianMovement_Request_signal goalorientation(::space_interfaces::srv::CartesianMovement_Request::_goalorientation_type arg)
  {
    msg_.goalorientation = std::move(arg);
    return Init_CartesianMovement_Request_signal(msg_);
  }

private:
  ::space_interfaces::srv::CartesianMovement_Request msg_;
};

class Init_CartesianMovement_Request_goalposition
{
public:
  Init_CartesianMovement_Request_goalposition()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianMovement_Request_goalorientation goalposition(::space_interfaces::srv::CartesianMovement_Request::_goalposition_type arg)
  {
    msg_.goalposition = std::move(arg);
    return Init_CartesianMovement_Request_goalorientation(msg_);
  }

private:
  ::space_interfaces::srv::CartesianMovement_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::CartesianMovement_Request>()
{
  return space_interfaces::srv::builder::Init_CartesianMovement_Request_goalposition();
}

}  // namespace space_interfaces


namespace space_interfaces
{

namespace srv
{

namespace builder
{

class Init_CartesianMovement_Response_message
{
public:
  explicit Init_CartesianMovement_Response_message(::space_interfaces::srv::CartesianMovement_Response & msg)
  : msg_(msg)
  {}
  ::space_interfaces::srv::CartesianMovement_Response message(::space_interfaces::srv::CartesianMovement_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::space_interfaces::srv::CartesianMovement_Response msg_;
};

class Init_CartesianMovement_Response_success
{
public:
  Init_CartesianMovement_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_CartesianMovement_Response_message success(::space_interfaces::srv::CartesianMovement_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_CartesianMovement_Response_message(msg_);
  }

private:
  ::space_interfaces::srv::CartesianMovement_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::space_interfaces::srv::CartesianMovement_Response>()
{
  return space_interfaces::srv::builder::Init_CartesianMovement_Response_success();
}

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__BUILDER_HPP_
