// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from space_interfaces:srv/JointEnable.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "space_interfaces/srv/detail/joint_enable__rosidl_typesupport_introspection_c.h"
#include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "space_interfaces/srv/detail/joint_enable__functions.h"
#include "space_interfaces/srv/detail/joint_enable__struct.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__JointEnable_Request__init(message_memory);
}

void JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_fini_function(void * message_memory)
{
  space_interfaces__srv__JointEnable_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_member_array[2] = {
  {
    "joint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__JointEnable_Request, joint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "data",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__JointEnable_Request, data),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_members = {
  "space_interfaces__srv",  // message namespace
  "JointEnable_Request",  // message name
  2,  // number of fields
  sizeof(space_interfaces__srv__JointEnable_Request),
  JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_member_array,  // message members
  JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_type_support_handle = {
  0,
  &JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Request)() {
  if (!JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_type_support_handle.typesupport_identifier) {
    JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &JointEnable_Request__rosidl_typesupport_introspection_c__JointEnable_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "space_interfaces/srv/detail/joint_enable__rosidl_typesupport_introspection_c.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "space_interfaces/srv/detail/joint_enable__functions.h"
// already included above
// #include "space_interfaces/srv/detail/joint_enable__struct.h"


// Include directives for member types
// Member `joint`
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__JointEnable_Response__init(message_memory);
}

void JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_fini_function(void * message_memory)
{
  space_interfaces__srv__JointEnable_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_member_array[3] = {
  {
    "joint",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__JointEnable_Response, joint),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__JointEnable_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__JointEnable_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_members = {
  "space_interfaces__srv",  // message namespace
  "JointEnable_Response",  // message name
  3,  // number of fields
  sizeof(space_interfaces__srv__JointEnable_Response),
  JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_member_array,  // message members
  JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_type_support_handle = {
  0,
  &JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Response)() {
  if (!JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_type_support_handle.typesupport_identifier) {
    JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &JointEnable_Response__rosidl_typesupport_introspection_c__JointEnable_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "space_interfaces/srv/detail/joint_enable__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_members = {
  "space_interfaces__srv",  // service namespace
  "JointEnable",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_Request_message_type_support_handle,
  NULL  // response message
  // space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_Response_message_type_support_handle
};

static rosidl_service_type_support_t space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_type_support_handle = {
  0,
  &space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable)() {
  if (!space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_type_support_handle.typesupport_identifier) {
    space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, JointEnable_Response)()->data;
  }

  return &space_interfaces__srv__detail__joint_enable__rosidl_typesupport_introspection_c__JointEnable_service_type_support_handle;
}
