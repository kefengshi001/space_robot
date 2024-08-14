// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:srv/CartesianMovement.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_H_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goalposition'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'goalorientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

// Struct defined in srv/CartesianMovement in the package space_interfaces.
typedef struct space_interfaces__srv__CartesianMovement_Request
{
  geometry_msgs__msg__Point goalposition;
  geometry_msgs__msg__Quaternion goalorientation;
  bool signal;
} space_interfaces__srv__CartesianMovement_Request;

// Struct for a sequence of space_interfaces__srv__CartesianMovement_Request.
typedef struct space_interfaces__srv__CartesianMovement_Request__Sequence
{
  space_interfaces__srv__CartesianMovement_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__CartesianMovement_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/CartesianMovement in the package space_interfaces.
typedef struct space_interfaces__srv__CartesianMovement_Response
{
  bool success;
  rosidl_runtime_c__String message;
} space_interfaces__srv__CartesianMovement_Response;

// Struct for a sequence of space_interfaces__srv__CartesianMovement_Response.
typedef struct space_interfaces__srv__CartesianMovement_Response__Sequence
{
  space_interfaces__srv__CartesianMovement_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__CartesianMovement_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_H_
