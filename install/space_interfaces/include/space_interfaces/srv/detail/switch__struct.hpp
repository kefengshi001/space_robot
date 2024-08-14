// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from space_interfaces:srv/Switch.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__SWITCH__STRUCT_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__SWITCH__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__Switch_Request __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__Switch_Request __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Switch_Request_
{
  using Type = Switch_Request_<ContainerAllocator>;

  explicit Switch_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_enable = false;
      this->adapter_status = false;
    }
  }

  explicit Switch_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->switch_enable = false;
      this->adapter_status = false;
    }
  }

  // field types and members
  using _switch_enable_type =
    bool;
  _switch_enable_type switch_enable;
  using _adapter_status_type =
    bool;
  _adapter_status_type adapter_status;

  // setters for named parameter idiom
  Type & set__switch_enable(
    const bool & _arg)
  {
    this->switch_enable = _arg;
    return *this;
  }
  Type & set__adapter_status(
    const bool & _arg)
  {
    this->adapter_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    space_interfaces::srv::Switch_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::Switch_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Switch_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Switch_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__Switch_Request
    std::shared_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__Switch_Request
    std::shared_ptr<space_interfaces::srv::Switch_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Switch_Request_ & other) const
  {
    if (this->switch_enable != other.switch_enable) {
      return false;
    }
    if (this->adapter_status != other.adapter_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const Switch_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Switch_Request_

// alias to use template instance with default allocator
using Switch_Request =
  space_interfaces::srv::Switch_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces


#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__Switch_Response __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__Switch_Response __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Switch_Response_
{
  using Type = Switch_Response_<ContainerAllocator>;

  explicit Switch_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Switch_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    space_interfaces::srv::Switch_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::Switch_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Switch_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Switch_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__Switch_Response
    std::shared_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__Switch_Response
    std::shared_ptr<space_interfaces::srv::Switch_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Switch_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Switch_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Switch_Response_

// alias to use template instance with default allocator
using Switch_Response =
  space_interfaces::srv::Switch_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces

namespace space_interfaces
{

namespace srv
{

struct Switch
{
  using Request = space_interfaces::srv::Switch_Request;
  using Response = space_interfaces::srv::Switch_Response;
};

}  // namespace srv

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__SWITCH__STRUCT_HPP_
