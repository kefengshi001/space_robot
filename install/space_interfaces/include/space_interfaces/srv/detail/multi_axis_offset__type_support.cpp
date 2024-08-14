// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from space_interfaces:srv/MultiAxisOffset.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "space_interfaces/srv/detail/multi_axis_offset__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace space_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void MultiAxisOffset_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) space_interfaces::srv::MultiAxisOffset_Request(_init);
}

void MultiAxisOffset_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<space_interfaces::srv::MultiAxisOffset_Request *>(message_memory);
  typed_message->~MultiAxisOffset_Request();
}

size_t size_function__MultiAxisOffset_Request__offsetangle(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<float> *>(untyped_member);
  return member->size();
}

const void * get_const_function__MultiAxisOffset_Request__offsetangle(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<float> *>(untyped_member);
  return &member[index];
}

void * get_function__MultiAxisOffset_Request__offsetangle(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<float> *>(untyped_member);
  return &member[index];
}

void resize_function__MultiAxisOffset_Request__offsetangle(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<float> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MultiAxisOffset_Request_message_member_array[1] = {
  {
    "offsetangle",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::srv::MultiAxisOffset_Request, offsetangle),  // bytes offset in struct
    nullptr,  // default value
    size_function__MultiAxisOffset_Request__offsetangle,  // size() function pointer
    get_const_function__MultiAxisOffset_Request__offsetangle,  // get_const(index) function pointer
    get_function__MultiAxisOffset_Request__offsetangle,  // get(index) function pointer
    resize_function__MultiAxisOffset_Request__offsetangle  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MultiAxisOffset_Request_message_members = {
  "space_interfaces::srv",  // message namespace
  "MultiAxisOffset_Request",  // message name
  1,  // number of fields
  sizeof(space_interfaces::srv::MultiAxisOffset_Request),
  MultiAxisOffset_Request_message_member_array,  // message members
  MultiAxisOffset_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  MultiAxisOffset_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MultiAxisOffset_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MultiAxisOffset_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace space_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<space_interfaces::srv::MultiAxisOffset_Request>()
{
  return &::space_interfaces::srv::rosidl_typesupport_introspection_cpp::MultiAxisOffset_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, space_interfaces, srv, MultiAxisOffset_Request)() {
  return &::space_interfaces::srv::rosidl_typesupport_introspection_cpp::MultiAxisOffset_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "space_interfaces/srv/detail/multi_axis_offset__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace space_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void MultiAxisOffset_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) space_interfaces::srv::MultiAxisOffset_Response(_init);
}

void MultiAxisOffset_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<space_interfaces::srv::MultiAxisOffset_Response *>(message_memory);
  typed_message->~MultiAxisOffset_Response();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember MultiAxisOffset_Response_message_member_array[2] = {
  {
    "success",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::srv::MultiAxisOffset_Response, success),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "message",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(space_interfaces::srv::MultiAxisOffset_Response, message),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers MultiAxisOffset_Response_message_members = {
  "space_interfaces::srv",  // message namespace
  "MultiAxisOffset_Response",  // message name
  2,  // number of fields
  sizeof(space_interfaces::srv::MultiAxisOffset_Response),
  MultiAxisOffset_Response_message_member_array,  // message members
  MultiAxisOffset_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  MultiAxisOffset_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t MultiAxisOffset_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MultiAxisOffset_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace space_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<space_interfaces::srv::MultiAxisOffset_Response>()
{
  return &::space_interfaces::srv::rosidl_typesupport_introspection_cpp::MultiAxisOffset_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, space_interfaces, srv, MultiAxisOffset_Response)() {
  return &::space_interfaces::srv::rosidl_typesupport_introspection_cpp::MultiAxisOffset_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "space_interfaces/srv/detail/multi_axis_offset__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace space_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers MultiAxisOffset_service_members = {
  "space_interfaces::srv",  // service namespace
  "MultiAxisOffset",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<space_interfaces::srv::MultiAxisOffset>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t MultiAxisOffset_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &MultiAxisOffset_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace space_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<space_interfaces::srv::MultiAxisOffset>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::space_interfaces::srv::rosidl_typesupport_introspection_cpp::MultiAxisOffset_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::space_interfaces::srv::MultiAxisOffset_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::space_interfaces::srv::MultiAxisOffset_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, space_interfaces, srv, MultiAxisOffset)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<space_interfaces::srv::MultiAxisOffset>();
}

#ifdef __cplusplus
}
#endif
