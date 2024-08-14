// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_HPP_
#define SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__space_interfaces__msg__JointJoggingMsg __attribute__((deprecated))
#else
# define DEPRECATED__space_interfaces__msg__JointJoggingMsg __declspec(deprecated)
#endif

namespace space_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JointJoggingMsg_
{
  using Type = JointJoggingMsg_<ContainerAllocator>;

  explicit JointJoggingMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint = "";
      this->run = false;
      this->signal = false;
    }
  }

  explicit JointJoggingMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : joint(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->joint = "";
      this->run = false;
      this->signal = false;
    }
  }

  // field types and members
  using _joint_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _joint_type joint;
  using _run_type =
    bool;
  _run_type run;
  using _signal_type =
    bool;
  _signal_type signal;

  // setters for named parameter idiom
  Type & set__joint(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->joint = _arg;
    return *this;
  }
  Type & set__run(
    const bool & _arg)
  {
    this->run = _arg;
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
    space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__space_interfaces__msg__JointJoggingMsg
    std::shared_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__space_interfaces__msg__JointJoggingMsg
    std::shared_ptr<space_interfaces::msg::JointJoggingMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JointJoggingMsg_ & other) const
  {
    if (this->joint != other.joint) {
      return false;
    }
    if (this->run != other.run) {
      return false;
    }
    if (this->signal != other.signal) {
      return false;
    }
    return true;
  }
  bool operator!=(const JointJoggingMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JointJoggingMsg_

// alias to use template instance with default allocator
using JointJoggingMsg =
  space_interfaces::msg::JointJoggingMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace space_interfaces

#endif  // SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__STRUCT_HPP_
