// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "space_interfaces/msg/detail/joint_jogging_msg__rosidl_typesupport_introspection_c.h"
#include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "space_interfaces/msg/detail/joint_jogging_msg__functions.h"
#include "space_interfaces/msg/detail/joint_jogging_msg__struct.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__msg__JointJoggingMsg__init(message_memory);
}

void JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_fini_function(void * message_memory)
{
  space_interfaces__msg__JointJoggingMsg__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_member_array[3] = {
  {
    "joint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__msg__JointJoggingMsg, joint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "run",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__msg__JointJoggingMsg, run),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "signal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__msg__JointJoggingMsg, signal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_members = {
  "space_interfaces__msg",  // message namespace
  "JointJoggingMsg",  // message name
  3,  // number of fields
  sizeof(space_interfaces__msg__JointJoggingMsg),
  JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_member_array,  // message members
  JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_type_support_handle = {
  0,
  &JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, msg, JointJoggingMsg)() {
  if (!JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_type_support_handle.typesupport_identifier) {
    JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &JointJoggingMsg__rosidl_typesupport_introspection_c__JointJoggingMsg_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
