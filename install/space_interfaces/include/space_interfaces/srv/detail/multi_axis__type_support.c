// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from space_interfaces:srv/MultiAxis.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "space_interfaces/srv/detail/multi_axis__rosidl_typesupport_introspection_c.h"
#include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "space_interfaces/srv/detail/multi_axis__functions.h"
#include "space_interfaces/srv/detail/multi_axis__struct.h"


// Include directives for member types
// Member `goalangle`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__MultiAxis_Request__init(message_memory);
}

void MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_fini_function(void * message_memory)
{
  space_interfaces__srv__MultiAxis_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_member_array[1] = {
  {
    "goalangle",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__MultiAxis_Request, goalangle),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_members = {
  "space_interfaces__srv",  // message namespace
  "MultiAxis_Request",  // message name
  1,  // number of fields
  sizeof(space_interfaces__srv__MultiAxis_Request),
  MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_member_array,  // message members
  MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_type_support_handle = {
  0,
  &MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Request)() {
  if (!MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_type_support_handle.typesupport_identifier) {
    MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MultiAxis_Request__rosidl_typesupport_introspection_c__MultiAxis_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "space_interfaces/srv/detail/multi_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "space_interfaces/srv/detail/multi_axis__functions.h"
// already included above
// #include "space_interfaces/srv/detail/multi_axis__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  space_interfaces__srv__MultiAxis_Response__init(message_memory);
}

void MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_fini_function(void * message_memory)
{
  space_interfaces__srv__MultiAxis_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces__srv__MultiAxis_Response, success),  // bytes offset in struct
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
    offsetof(space_interfaces__srv__MultiAxis_Response, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_members = {
  "space_interfaces__srv",  // message namespace
  "MultiAxis_Response",  // message name
  2,  // number of fields
  sizeof(space_interfaces__srv__MultiAxis_Response),
  MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_member_array,  // message members
  MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_type_support_handle = {
  0,
  &MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Response)() {
  if (!MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_type_support_handle.typesupport_identifier) {
    MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MultiAxis_Response__rosidl_typesupport_introspection_c__MultiAxis_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "space_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "space_interfaces/srv/detail/multi_axis__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_members = {
  "space_interfaces__srv",  // service namespace
  "MultiAxis",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_Request_message_type_support_handle,
  NULL  // response message
  // space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_Response_message_type_support_handle
};

static rosidl_service_type_support_t space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_type_support_handle = {
  0,
  &space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_space_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis)() {
  if (!space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_type_support_handle.typesupport_identifier) {
    space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, space_interfaces, srv, MultiAxis_Response)()->data;
  }

  return &space_interfaces__srv__detail__multi_axis__rosidl_typesupport_introspection_c__MultiAxis_service_type_support_handle;
}
