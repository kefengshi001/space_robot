// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from space_interfaces:srv/CartesianMovement.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_HPP_
#define SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'goalposition'
#include "geometry_msgs/msg/detail/point__struct.hpp"
// Member 'goalorientation'
#include "geometry_msgs/msg/detail/quaternion__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__CartesianMovement_Request __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__CartesianMovement_Request __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CartesianMovement_Request_
{
  using Type = CartesianMovement_Request_<ContainerAllocator>;

  explicit CartesianMovement_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goalposition(_init),
    goalorientation(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->signal = false;
    }
  }

  explicit CartesianMovement_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : goalposition(_alloc, _init),
    goalorientation(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->signal = false;
    }
  }

  // field types and members
  using _goalposition_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _goalposition_type goalposition;
  using _goalorientation_type =
    geometry_msgs::msg::Quaternion_<ContainerAllocator>;
  _goalorientation_type goalorientation;
  using _signal_type =
    bool;
  _signal_type signal;

  // setters for named parameter idiom
  Type & set__goalposition(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->goalposition = _arg;
    return *this;
  }
  Type & set__goalorientation(
    const geometry_msgs::msg::Quaternion_<ContainerAllocator> & _arg)
  {
    this->goalorientation = _arg;
    return *this;
  }
  Type & set__signal(
    const bool & _arg)
  {
    this->signal = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__CartesianMovement_Request
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__CartesianMovement_Request
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianMovement_Request_ & other) const
  {
    if (this->goalposition != other.goalposition) {
      return false;
    }
    if (this->goalorientation != other.goalorientation) {
      return false;
    }
    if (this->signal != other.signal) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianMovement_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianMovement_Request_

// alias to use template instance with default allocator
using CartesianMovement_Request =
  space_interfaces::srv::CartesianMovement_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces


#ifndef _WIN32
# define DEPRECATED__space_interfaces__srv__CartesianMovement_Response __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__srv__CartesianMovement_Response __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct CartesianMovement_Response_
{
  using Type = CartesianMovement_Response_<ContainerAllocator>;

  explicit CartesianMovement_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit CartesianMovement_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__srv__CartesianMovement_Response
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__srv__CartesianMovement_Response
    std::shared_ptr<space_interfaces::srv::CartesianMovement_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const CartesianMovement_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const CartesianMovement_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct CartesianMovement_Response_

// alias to use template instance with default allocator
using CartesianMovement_Response =
  space_interfaces::srv::CartesianMovement_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace space_interfaces

namespace space_interfaces
{

namespace srv
{

struct CartesianMovement
{
  using Request = space_interfaces::srv::CartesianMovement_Request;
  using Response = space_interfaces::srv::CartesianMovement_Response;
};

}  // namespace srv

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__SRV__DETAIL__CARTESIAN_MOVEMENT__STRUCT_HPP_
