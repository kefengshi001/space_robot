// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from space_interfaces:srv/JointEnable.idl
// generated code does not contain a copyright notice

#ifndef SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__FUNCTIONS_H_
#define SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "space_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "space_interfaces/srv/detail/joint_enable__struct.h"

/// Initialize srv/JointEnable message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * space_interfaces__srv__JointEnable_Request
 * )) before or use
 * space_interfaces__srv__JointEnable_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Request__init(space_interfaces__srv__JointEnable_Request * msg);

/// Finalize srv/JointEnable message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Request__fini(space_interfaces__srv__JointEnable_Request * msg);

/// Create srv/JointEnable message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * space_interfaces__srv__JointEnable_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__srv__JointEnable_Request *
space_interfaces__srv__JointEnable_Request__create();

/// Destroy srv/JointEnable message.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Request__destroy(space_interfaces__srv__JointEnable_Request * msg);

/// Check for srv/JointEnable message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Request__are_equal(const space_interfaces__srv__JointEnable_Request * lhs, const space_interfaces__srv__JointEnable_Request * rhs);

/// Copy a srv/JointEnable message.
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
space_interfaces__srv__JointEnable_Request__copy(
  const space_interfaces__srv__JointEnable_Request * input,
  space_interfaces__srv__JointEnable_Request * output);

/// Initialize array of srv/JointEnable messages.
/**
 * It allocates the memory for the number of elements and calls
 * space_interfaces__srv__JointEnable_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Request__Sequence__init(space_interfaces__srv__JointEnable_Request__Sequence * array, size_t size);

/// Finalize array of srv/JointEnable messages.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Request__Sequence__fini(space_interfaces__srv__JointEnable_Request__Sequence * array);

/// Create array of srv/JointEnable messages.
/**
 * It allocates the memory for the array and calls
 * space_interfaces__srv__JointEnable_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__srv__JointEnable_Request__Sequence *
space_interfaces__srv__JointEnable_Request__Sequence__create(size_t size);

/// Destroy array of srv/JointEnable messages.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Request__Sequence__destroy(space_interfaces__srv__JointEnable_Request__Sequence * array);

/// Check for srv/JointEnable message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Request__Sequence__are_equal(const space_interfaces__srv__JointEnable_Request__Sequence * lhs, const space_interfaces__srv__JointEnable_Request__Sequence * rhs);

/// Copy an array of srv/JointEnable messages.
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
space_interfaces__srv__JointEnable_Request__Sequence__copy(
  const space_interfaces__srv__JointEnable_Request__Sequence * input,
  space_interfaces__srv__JointEnable_Request__Sequence * output);

/// Initialize srv/JointEnable message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * space_interfaces__srv__JointEnable_Response
 * )) before or use
 * space_interfaces__srv__JointEnable_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Response__init(space_interfaces__srv__JointEnable_Response * msg);

/// Finalize srv/JointEnable message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Response__fini(space_interfaces__srv__JointEnable_Response * msg);

/// Create srv/JointEnable message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * space_interfaces__srv__JointEnable_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__srv__JointEnable_Response *
space_interfaces__srv__JointEnable_Response__create();

/// Destroy srv/JointEnable message.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Response__destroy(space_interfaces__srv__JointEnable_Response * msg);

/// Check for srv/JointEnable message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Response__are_equal(const space_interfaces__srv__JointEnable_Response * lhs, const space_interfaces__srv__JointEnable_Response * rhs);

/// Copy a srv/JointEnable message.
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
space_interfaces__srv__JointEnable_Response__copy(
  const space_interfaces__srv__JointEnable_Response * input,
  space_interfaces__srv__JointEnable_Response * output);

/// Initialize array of srv/JointEnable messages.
/**
 * It allocates the memory for the number of elements and calls
 * space_interfaces__srv__JointEnable_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Response__Sequence__init(space_interfaces__srv__JointEnable_Response__Sequence * array, size_t size);

/// Finalize array of srv/JointEnable messages.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Response__Sequence__fini(space_interfaces__srv__JointEnable_Response__Sequence * array);

/// Create array of srv/JointEnable messages.
/**
 * It allocates the memory for the array and calls
 * space_interfaces__srv__JointEnable_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
space_interfaces__srv__JointEnable_Response__Sequence *
space_interfaces__srv__JointEnable_Response__Sequence__create(size_t size);

/// Destroy array of srv/JointEnable messages.
/**
 * It calls
 * space_interfaces__srv__JointEnable_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
void
space_interfaces__srv__JointEnable_Response__Sequence__destroy(space_interfaces__srv__JointEnable_Response__Sequence * array);

/// Check for srv/JointEnable message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_space_interfaces
bool
space_interfaces__srv__JointEnable_Response__Sequence__are_equal(const space_interfaces__srv__JointEnable_Response__Sequence * lhs, const space_interfaces__srv__JointEnable_Response__Sequence * rhs);

/// Copy an array of srv/JointEnable messages.
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
space_interfaces__srv__JointEnable_Response__Sequence__copy(
  const space_interfaces__srv__JointEnable_Response__Sequence * input,
  space_interfaces__srv__JointEnable_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // SPACE_INTERFACES__SRV__DETAIL__JOINT_ENABLE__FUNCTIONS_H_