// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from space_interfaces:srv/CartesianMovement.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__TRAITS_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__TRAITS_HPP_

#include "space_interfaces/srv/detail/cartesian_movement__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'goalposition'
#include "geometry_msgs/msg/detail/point__traits.hpp"
// Member 'goalorientation'
#include "geometry_msgs/msg/detail/quaternion__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianMovement_Request>()
{
  return "space_interfaces::srv::CartesianMovement_Request";
}

template<>
inline const char * name<space_interfaces::srv::CartesianMovement_Request>()
{
  return "space_interfaces/srv/CartesianMovement_Request";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianMovement_Request>
  : std::integral_constant<bool, has_fixed_size<geometry_msgs::msg::Point>::value && has_fixed_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianMovement_Request>
  : std::integral_constant<bool, has_bounded_size<geometry_msgs::msg::Point>::value && has_bounded_size<geometry_msgs::msg::Quaternion>::value> {};

template<>
struct is_message<space_interfaces::srv::CartesianMovement_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianMovement_Response>()
{
  return "space_interfaces::srv::CartesianMovement_Response";
}

template<>
inline const char * name<space_interfaces::srv::CartesianMovement_Response>()
{
  return "space_interfaces/srv/CartesianMovement_Response";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianMovement_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianMovement_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<space_interfaces::srv::CartesianMovement_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<space_interfaces::srv::CartesianMovement>()
{
  return "space_interfaces::srv::CartesianMovement";
}

template<>
inline const char * name<space_interfaces::srv::CartesianMovement>()
{
  return "space_interfaces/srv/CartesianMovement";
}

template<>
struct has_fixed_size<space_interfaces::srv::CartesianMovement>
  : std::integral_constant<
    bool,
    has_fixed_size<space_interfaces::srv::CartesianMovement_Request>::value &&
    has_fixed_size<space_interfaces::srv::CartesianMovement_Response>::value
  >
{
};

template<>
struct has_bounded_size<space_interfaces::srv::CartesianMovement>
  : std::integral_constant<
    bool,
    has_bounded_size<space_interfaces::srv::CartesianMovement_Request>::value &&
    has_bounded_size<space_interfaces::srv::CartesianMovement_Response>::value
  >
{
};

template<>
struct is_service<space_interfaces::srv::CartesianMovement>
  : std::true_type
{
};

template<>
struct is_service_request<space_interfaces::srv::CartesianMovement_Request>
  : std::true_type
{
};

template<>
struct is_service_response<space_interfaces::srv::CartesianMovement_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__TRAITS_HPP_
