// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__TRAITS_HPP_
#define SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__TRAITS_HPP_

#include "space_interfaces/msg/detail/joint_jogging_msg__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::msg::JointJoggingMsg>()
{
  return "space_interfaces::msg::JointJoggingMsg";
}

template<>
inline const char * name<space_interfaces::msg::JointJoggingMsg>()
{
  return "space_interfaces/msg/JointJoggingMsg";
}

template<>
struct has_fixed_size<space_interfaces::msg::JointJoggingMsg>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<space_interfaces::msg::JointJoggingMsg>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<space_interfaces::msg::JointJoggingMsg>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__TRAITS_HPP_
