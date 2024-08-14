// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
#define SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'jointposition'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'orientation'
#include "geometry_msgs/msg/detail/quaternion__struct.h"

// Struct defined in msg/RobotState in the package space_interfaces.
typedef struct space_interfaces__msg__RobotState
{
  rosidl_runtime_c__float__Sequence jointposition;
  geometry_msgs__msg__Point position;
  geometry_msgs__msg__Quaternion orientation;
} space_interfaces__msg__RobotState;

// Struct for a sequence of space_interfaces__msg__RobotState.
typedef struct space_interfaces__msg__RobotState__Sequence
{
  space_interfaces__msg__RobotState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__msg__RobotState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__MSG__DETAIL__ROBOT_STATE__STRUCT_H_
