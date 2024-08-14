// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from space_interfaces:srv/Connection.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_H_
#define SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/Connection in the package space_interfaces.
typedef struct space_interfaces__srv__Connection_Request
{
  bool connect;
} space_interfaces__srv__Connection_Request;

// Struct for a sequence of space_interfaces__srv__Connection_Request.
typedef struct space_interfaces__srv__Connection_Request__Sequence
{
  space_interfaces__srv__Connection_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__Connection_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/Connection in the package space_interfaces.
typedef struct space_interfaces__srv__Connection_Response
{
  bool success;
} space_interfaces__srv__Connection_Response;

// Struct for a sequence of space_interfaces__srv__Connection_Response.
typedef struct space_interfaces__srv__Connection_Response__Sequence
{
  space_interfaces__srv__Connection_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} space_interfaces__srv__Connection_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_H_
