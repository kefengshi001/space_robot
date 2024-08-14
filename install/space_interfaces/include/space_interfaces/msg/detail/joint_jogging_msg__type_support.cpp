// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "space_interfaces/msg/detail/joint_jogging_msg__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace space_interfaces
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void JointJoggingMsg_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) space_interfaces::msg::JointJoggingMsg(_init);
}

void JointJoggingMsg_fini_function(void * message_memory)
{
  auto typed_message = static_cast<space_interfaces::msg::JointJoggingMsg *>(message_memory);
  typed_message->~JointJoggingMsg();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember JointJoggingMsg_message_member_array[3] = {
  {
    "joint",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::msg::JointJoggingMsg, joint),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "run",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::msg::JointJoggingMsg, run),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "signal",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::msg::JointJoggingMsg, signal),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers JointJoggingMsg_message_members = {
  "space_interfaces::msg",  // message namespace
  "JointJoggingMsg",  // message name
  3,  // number of fields
  sizeof(space_interfaces::msg::JointJoggingMsg),
  JointJoggingMsg_message_member_array,  // message members
  JointJoggingMsg_init_function,  // function to initialize message memory (memory has to be allocated)
  JointJoggingMsg_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t JointJoggingMsg_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &JointJoggingMsg_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace space_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<space_interfaces::msg::JointJoggingMsg>()
{
  return &::space_interfaces::msg::rosidl_typesupport_introspection_cpp::JointJoggingMsg_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, space_interfaces, msg, JointJoggingMsg)() {
  return &::space_interfaces::msg::rosidl_typesupport_introspection_cpp::JointJoggingMsg_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif