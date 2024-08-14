// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from space_interfaces:srv/Connection.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__Connection_Request __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__Connection_Request __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Connection_Request_
{
  using Type = Connection_Request_<ContainerAllocator>;

  explicit Connection_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connect = false;
    }
  }

  explicit Connection_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->connect = false;
    }
  }

  // field types and members
  using _connect_type =
    bool;
  _connect_type connect;

  // setters for named parameter idiom
  Type & set__connect(
    const bool & _arg)
  {
    this->connect = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    space_interfaces::srv::Connection_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::Connection_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Connection_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Connection_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__Connection_Request
    std::shared_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__Connection_Request
    std::shared_ptr<space_interfaces::srv::Connection_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Connection_Request_ & other) const
  {
    if (this->connect != other.connect) {
      return false;
    }
    return true;
  }
  bool operator!=(const Connection_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Connection_Request_

// alias to use template instance with default allocator
using Connection_Request =
  space_interfaces::srv::Connection_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces


#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__Connection_Response __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__Connection_Response __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Connection_Response_
{
  using Type = Connection_Response_<ContainerAllocator>;

  explicit Connection_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
    }
  }

  explicit Connection_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    space_interfaces::srv::Connection_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::Connection_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Connection_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::Connection_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__Connection_Response
    std::shared_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__Connection_Response
    std::shared_ptr<space_interfaces::srv::Connection_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Connection_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    return true;
  }
  bool operator!=(const Connection_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Connection_Response_

// alias to use template instance with default allocator
using Connection_Response =
  space_interfaces::srv::Connection_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces

namespace space_interfaces
{

namespace srv
{

struct Connection
{
  using Request = space_interfaces::srv::Connection_Request;
  using Response = space_interfaces::srv::Connection_Response;
};

}  // namespace srv

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__CONNECTION__STRUCT_HPP_
