// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from space_interfaces:srv/SpeedSet.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__TRAITS_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__TRAITS_HPP_

#include "space_interfaces/srv/detail/speed_set__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::SpeedSet_Request>()
{
  return "space_interfaces::srv::SpeedSet_Request";
}

template<>
inline const char * name<space_interfaces::srv::SpeedSet_Request>()
{
  return "space_interfaces/srv/SpeedSet_Request";
}

template<>
struct has_fixed_size<space_interfaces::srv::SpeedSet_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<space_interfaces::srv::SpeedSet_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<space_interfaces::srv::SpeedSet_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::SpeedSet_Response>()
{
  return "space_interfaces::srv::SpeedSet_Response";
}

template<>
inline const char * name<space_interfaces::srv::SpeedSet_Response>()
{
  return "space_interfaces/srv/SpeedSet_Response";
}

template<>
struct has_fixed_size<space_interfaces::srv::SpeedSet_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<space_interfaces::srv::SpeedSet_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<space_interfaces::srv::SpeedSet_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::SpeedSet>()
{
  return "space_interfaces::srv::SpeedSet";
}

template<>
inline const char * name<space_interfaces::srv::SpeedSet>()
{
  return "space_interfaces/srv/SpeedSet";
}

template<>
struct has_fixed_size<space_interfaces::srv::SpeedSet>
  : std::integral_constant<
    bool,
    has_fixed_size<space_interfaces::srv::SpeedSet_Request>::value &&
    has_fixed_size<space_interfaces::srv::SpeedSet_Response>::value
  >
{
};

template<>
struct has_bounded_size<space_interfaces::srv::SpeedSet>
  : std::integral_constant<
    bool,
    has_bounded_size<space_interfaces::srv::SpeedSet_Request>::value &&
    has_bounded_size<space_interfaces::srv::SpeedSet_Response>::value
  >
{
};

template<>
struct is_service<space_interfaces::srv::SpeedSet>
  : std::true_type
{
};

template<>
struct is_service_request<space_interfaces::srv::SpeedSet_Request>
  : std::true_type
{
};

template<>
struct is_service_response<space_interfaces::srv::SpeedSet_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPACE_INTERFACES__SRV__DETAIL__SPEED_SET__TRAITS_HPP_
