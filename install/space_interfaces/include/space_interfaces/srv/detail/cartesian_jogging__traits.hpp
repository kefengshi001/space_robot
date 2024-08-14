// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from space_interfaces:srv/CartesianJogging.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__TRAITS_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__TRAITS_HPP_

#include "space_interfaces/srv/detail/cartesian_jogging__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianJogging_Request>()
{
  return "space_interfaces::srv::CartesianJogging_Request";
}

template<>
inline const char * name<space_interfaces::srv::CartesianJogging_Request>()
{
  return "space_interfaces/srv/CartesianJogging_Request";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianJogging_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianJogging_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<space_interfaces::srv::CartesianJogging_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianJogging_Response>()
{
  return "space_interfaces::srv::CartesianJogging_Response";
}

template<>
inline const char * name<space_interfaces::srv::CartesianJogging_Response>()
{
  return "space_interfaces/srv/CartesianJogging_Response";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianJogging_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianJogging_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<space_interfaces::srv::CartesianJogging_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianJogging>()
{
  return "space_interfaces::srv::CartesianJogging";
}

template<>
inline const char * name<space_interfaces::srv::CartesianJogging>()
{
  return "space_interfaces/srv/CartesianJogging";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianJogging>
  : std::integral_constant<
    bool,
    has_fixed_size<space_interfaces::srv::CartesianJogging_Request>::value &&
    has_fixed_size<space_interfaces::srv::CartesianJogging_Response>::value
  >
{
};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianJogging>
  : std::integral_constant<
    bool,
    has_bounded_size<space_interfaces::srv::CartesianJogging_Request>::value &&
    has_bounded_size<space_interfaces::srv::CartesianJogging_Response>::value
  >
{
};

template<>
struct is_service<space_interfaces::srv::CartesianJogging>
  : std::true_type
{
};

template<>
struct is_service_request<space_interfaces::srv::CartesianJogging_Request>
  : std::true_type
{
};

template<>
struct is_service_response<space_interfaces::srv::CartesianJogging_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__TRAITS_HPP_
