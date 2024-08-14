// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:srv/MultiAxis.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__STRUCT_H_
#define SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'goalangle'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/MultiAxis in the package space_interfaces.
typedef struct space_interfaces__srv__MultiAxis_Request
{
  rosidl_runtime_c__float__Sequence goalangle;
} space_interfaces__srv__MultiAxis_Request;

// Struct for a sequence of space_interfaces__srv__MultiAxis_Request.
typedef struct space_interfaces__srv__MultiAxis_Request__Sequence
{
  space_interfaces__srv__MultiAxis_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__MultiAxis_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/MultiAxis in the package space_interfaces.
typedef struct space_interfaces__srv__MultiAxis_Response
{
  bool success;
  rosidl_runtime_c__String message;
} space_interfaces__srv__MultiAxis_Response;

// Struct for a sequence of space_interfaces__srv__MultiAxis_Response.
typedef struct space_interfaces__srv__MultiAxis_Response__Sequence
{
  space_interfaces__srv__MultiAxis_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__MultiAxis_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__MULTI_AXIS__STRUCT_H_
