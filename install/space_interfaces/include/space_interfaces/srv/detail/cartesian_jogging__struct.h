// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:srv/CartesianJogging.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__STRUCT_H_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'axis'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/CartesianJogging in the package space_interfaces.
typedef struct space_interfaces__srv__CartesianJogging_Request
{
  rosidl_runtime_c__String axis;
  bool run;
  bool signal;
} space_interfaces__srv__CartesianJogging_Request;

// Struct for a sequence of space_interfaces__srv__CartesianJogging_Request.
typedef struct space_interfaces__srv__CartesianJogging_Request__Sequence
{
  space_interfaces__srv__CartesianJogging_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__CartesianJogging_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/CartesianJogging in the package space_interfaces.
typedef struct space_interfaces__srv__CartesianJogging_Response
{
  bool success;
  rosidl_runtime_c__String message;
} space_interfaces__srv__CartesianJogging_Response;

// Struct for a sequence of space_interfaces__srv__CartesianJogging_Response.
typedef struct space_interfaces__srv__CartesianJogging_Response__Sequence
{
  space_interfaces__srv__CartesianJogging_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__CartesianJogging_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_JOGGING__STRUCT_H_
