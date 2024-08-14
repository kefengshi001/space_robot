// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_H_
#define SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_H_

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

// Struct defined in msg/JointJoggingMsg in the package space_interfaces.
typedef struct space_interfaces__msg__JointJoggingMsg
{
  rosidl_runtime_c__String joint;
  bool run;
  bool signal;
} space_interfaces__msg__JointJoggingMsg;

// Struct for a sequence of space_interfaces__msg__JointJoggingMsg.
typedef struct space_interfaces__msg__JointJoggingMsg__Sequence
{
  space_interfaces__msg__JointJoggingMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__msg__JointJoggingMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_H_
