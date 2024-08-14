// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__FUNCTIONS_H_
#define SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "space_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "space_interfaces/msg/detail/joint_jogging_msg__struct.h"

/// Initialize msg/JointJoggingMsg message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * space_interfaces__msg__JointJoggingMsg
 * )) before or use
 * space_interfaces__msg__JointJoggingMsg__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__init(space_interfaces__msg__JointJoggingMsg * msg);

/// Finalize msg/JointJoggingMsg message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__msg__JointJoggingMsg__fini(space_interfaces__msg__JointJoggingMsg * msg);

/// Create msg/JointJoggingMsg message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * space_interfaces__msg__JointJoggingMsg__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__msg__JointJoggingMsg *
space_interfaces__msg__JointJoggingMsg__create();

/// Destroy msg/JointJoggingMsg message.
/**
 * It calls
 * space_interfaces__msg__JointJoggingMsg__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__msg__JointJoggingMsg__destroy(space_interfaces__msg__JointJoggingMsg * msg);

/// Check for msg/JointJoggingMsg message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__are_equal(const space_interfaces__msg__JointJoggingMsg * lhs, const space_interfaces__msg__JointJoggingMsg * rhs);

/// Copy a msg/JointJoggingMsg message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__copy(
  const space_interfaces__msg__JointJoggingMsg * input,
  space_interfaces__msg__JointJoggingMsg * output);

/// Initialize array of msg/JointJoggingMsg messages.
/**
 * It allocates the memory for the number of elements and calls
 * space_interfaces__msg__JointJoggingMsg__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__Sequence__init(space_interfaces__msg__JointJoggingMsg__Sequence * array, size_t size);

/// Finalize array of msg/JointJoggingMsg messages.
/**
 * It calls
 * space_interfaces__msg__JointJoggingMsg__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__msg__JointJoggingMsg__Sequence__fini(space_interfaces__msg__JointJoggingMsg__Sequence * array);

/// Create array of msg/JointJoggingMsg messages.
/**
 * It allocates the memory for the array and calls
 * space_interfaces__msg__JointJoggingMsg__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__msg__JointJoggingMsg__Sequence *
space_interfaces__msg__JointJoggingMsg__Sequence__create(size_t size);

/// Destroy array of msg/JointJoggingMsg messages.
/**
 * It calls
 * space_interfaces__msg__JointJoggingMsg__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__msg__JointJoggingMsg__Sequence__destroy(space_interfaces__msg__JointJoggingMsg__Sequence * array);

/// Check for msg/JointJoggingMsg message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__Sequence__are_equal(const space_interfaces__msg__JointJoggingMsg__Sequence * lhs, const space_interfaces__msg__JointJoggingMsg__Sequence * rhs);

/// Copy an array of msg/JointJoggingMsg messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__msg__JointJoggingMsg__Sequence__copy(
  const space_interfaces__msg__JointJoggingMsg__Sequence * input,
  space_interfaces__msg__JointJoggingMsg__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__MSG__DETAIL__JOINT_JOGGING_MSG__FUNCTIONS_H_
