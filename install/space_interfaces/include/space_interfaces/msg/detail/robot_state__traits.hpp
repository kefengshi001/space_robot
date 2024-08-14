// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from space_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
#define SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_

#include "space_interfaces/msg/detail/robot_state__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'position'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::msg::RobotState>()
{
  return "space_interfaces::msg::RobotState";
}

template<>
inline const char * name<space_interfaces::msg::RobotState>()
{
  return "space_interfaces/msg/RobotState";
}

template<>
struct has_fixed_size<space_interfaces::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<space_interfaces::msg::RobotState>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<space_interfaces::msg::RobotState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__TRAITS_HPP_
