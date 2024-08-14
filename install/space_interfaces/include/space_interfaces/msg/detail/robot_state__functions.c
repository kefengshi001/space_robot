// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from space_interfaces:msg/RobotState.idl
// generated code does not contain a copyright notice
#include "space_interfaces/msg/detail/robot_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `jointposition`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `position`
#include "geometry_msgs/msg/detail/point__functions.h"
// Member `orientation`
#include "geometry_msgs/msg/detail/quaternion__functions.h"

bool
space_interfaces__msg__RobotState__init(space_interfaces__msg__RobotState * msg)
{
  if (!msg) {
    return false;
  }
  // jointposition
  if (!rosidl_runtime_c__float__Sequence__init(&msg->jointposition, 0)) {
    space_interfaces__msg__RobotState__fini(msg);
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__init(&msg->position)) {
    space_interfaces__msg__RobotState__fini(msg);
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__init(&msg->orientation)) {
    space_interfaces__msg__RobotState__fini(msg);
    return false;
  }
  return true;
}

void
space_interfaces__msg__RobotState__fini(space_interfaces__msg__RobotState * msg)
{
  if (!msg) {
    return;
  }
  // jointposition
  rosidl_runtime_c__float__Sequence__fini(&msg->jointposition);
  // position
  geometry_msgs__msg__Point__fini(&msg->position);
  // orientation
  geometry_msgs__msg__Quaternion__fini(&msg->orientation);
}

bool
space_interfaces__msg__RobotState__are_equal(const space_interfaces__msg__RobotState * lhs, const space_interfaces__msg__RobotState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // jointposition
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->jointposition), &(rhs->jointposition)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position), &(rhs->position)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__are_equal(
      &(lhs->orientation), &(rhs->orientation)))
  {
    return false;
  }
  return true;
}

bool
space_interfaces__msg__RobotState__copy(
  const space_interfaces__msg__RobotState * input,
  space_interfaces__msg__RobotState * output)
{
  if (!input || !output) {
    return false;
  }
  // jointposition
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->jointposition), &(output->jointposition)))
  {
    return false;
  }
  // position
  if (!geometry_msgs__msg__Point__copy(
      &(input->position), &(output->position)))
  {
    return false;
  }
  // orientation
  if (!geometry_msgs__msg__Quaternion__copy(
      &(input->orientation), &(output->orientation)))
  {
    return false;
  }
  return true;
}

space_interfaces__msg__RobotState *
space_interfaces__msg__RobotState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__RobotState * msg = (space_interfaces__msg__RobotState *)allocator.allocate(sizeof(space_interfaces__msg__RobotState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(space_interfaces__msg__RobotState));
  bool success = space_interfaces__msg__RobotState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
space_interfaces__msg__RobotState__destroy(space_interfaces__msg__RobotState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    space_interfaces__msg__RobotState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
space_interfaces__msg__RobotState__Sequence__init(space_interfaces__msg__RobotState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__RobotState * data = NULL;

  if (size) {
    data = (space_interfaces__msg__RobotState *)allocator.zero_allocate(size, sizeof(space_interfaces__msg__RobotState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = space_interfaces__msg__RobotState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        space_interfaces__msg__RobotState__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
space_interfaces__msg__RobotState__Sequence__fini(space_interfaces__msg__RobotState__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      space_interfaces__msg__RobotState__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

space_interfaces__msg__RobotState__Sequence *
space_interfaces__msg__RobotState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__RobotState__Sequence * array = (space_interfaces__msg__RobotState__Sequence *)allocator.allocate(sizeof(space_interfaces__msg__RobotState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = space_interfaces__msg__RobotState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
space_interfaces__msg__RobotState__Sequence__destroy(space_interfaces__msg__RobotState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    space_interfaces__msg__RobotState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
space_interfaces__msg__RobotState__Sequence__are_equal(const space_interfaces__msg__RobotState__Sequence * lhs, const space_interfaces__msg__RobotState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!space_interfaces__msg__RobotState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
space_interfaces__msg__RobotState__Sequence__copy(
  const space_interfaces__msg__RobotState__Sequence * input,
  space_interfaces__msg__RobotState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(space_interfaces__msg__RobotState);
    space_interfaces__msg__RobotState * data =
      (space_interfaces__msg__RobotState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!space_interfaces__msg__RobotState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          space_interfaces__msg__RobotState__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!space_interfaces__msg__RobotState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
