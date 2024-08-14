// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from space_interfaces:srv/SpeedSet.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "space_interfaces/srv/detail/speed_set__rosidl_typesupport_introspection_c.h"
#include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "space_interfaces/srv/detail/speed_set__functions.h"
#include "space_interfaces/srv/detail/speed_set__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__SpeedSet_Request__init(message_memory);
}

void SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_fini_function(void * message_memory)
{
  space_interfaces__srv__SpeedSet_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_member_array[1] = {
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__SpeedSet_Request, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_members = {
  "space_interfaces__srv",  // message namespace
  "SpeedSet_Request",  // message name
  1,  // number of fields
  sizeof(space_interfaces__srv__SpeedSet_Request),
  SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_member_array,  // message members
  SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_type_support_handle = {
  0,
  &SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Request)() {
  if (!SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_type_support_handle.typesupport_identifier) {
    SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SpeedSet_Request__rosidl_typesupport_introspection_c__SpeedSet_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "space_interfaces/srv/detail/speed_set__rosidl_typesupport_introspection_c.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "space_interfaces/srv/detail/speed_set__functions.h"
// already included above
// #include "space_interfaces/srv/detail/speed_set__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__SpeedSet_Response__init(message_memory);
}

void SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_fini_function(void * message_memory)
{
  space_interfaces__srv__SpeedSet_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_member_array[1] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__SpeedSet_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_members = {
  "space_interfaces__srv",  // message namespace
  "SpeedSet_Response",  // message name
  1,  // number of fields
  sizeof(space_interfaces__srv__SpeedSet_Response),
  SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_member_array,  // message members
  SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_type_support_handle = {
  0,
  &SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Response)() {
  if (!SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_type_support_handle.typesupport_identifier) {
    SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SpeedSet_Response__rosidl_typesupport_introspection_c__SpeedSet_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "space_interfaces/srv/detail/speed_set__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_members = {
  "space_interfaces__srv",  // service namespace
  "SpeedSet",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_Request_message_type_support_handle,
  NULL  // response message
  // space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_Response_message_type_support_handle
};

static rosidl_service_type_support_t space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_type_support_handle = {
  0,
  &space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet)() {
  if (!space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_type_support_handle.typesupport_identifier) {
    space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, SpeedSet_Response)()->data;
  }

  return &space_interfaces__srv__detail__speed_set__rosidl_typesupport_introspection_c__SpeedSet_service_type_support_handle;
}
