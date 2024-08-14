// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:srv/JointJogging.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__STRUCT_H_
#define SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'joint'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/JointJogging in the package space_interfaces.
typedef struct space_interfaces__srv__JointJogging_Request
{
  rosidl_runtime_c__String joint;
  bool run;
  bool signal;
} space_interfaces__srv__JointJogging_Request;

// Struct for a sequence of space_interfaces__srv__JointJogging_Request.
typedef struct space_interfaces__srv__JointJogging_Request__Sequence
{
  space_interfaces__srv__JointJogging_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__JointJogging_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/JointJogging in the package space_interfaces.
typedef struct space_interfaces__srv__JointJogging_Response
{
  bool success;
  rosidl_runtime_c__String message;
} space_interfaces__srv__JointJogging_Response;

// Struct for a sequence of space_interfaces__srv__JointJogging_Response.
typedef struct space_interfaces__srv__JointJogging_Response__Sequence
{
  space_interfaces__srv__JointJogging_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__JointJogging_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__JOINT_JOGGING__STRUCT_H_
