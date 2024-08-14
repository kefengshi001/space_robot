// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from space_interfaces:msg/JointJoggingMsg.idl
// generated code does not contain a copyright notice
#include "space_interfaces/msg/detail/joint_jogging_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `joint`
#include "rosidl_runtime_c/string_functions.h"

bool
space_interfaces__msg__JointJoggingMsg__init(space_interfaces__msg__JointJoggingMsg * msg)
{
  if (!msg) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__String__init(&msg->joint)) {
    space_interfaces__msg__JointJoggingMsg__fini(msg);
    return false;
  }
  // run
  // signal
  return true;
}

void
space_interfaces__msg__JointJoggingMsg__fini(space_interfaces__msg__JointJoggingMsg * msg)
{
  if (!msg) {
    return;
  }
  // joint
  rosidl_runtime_c__String__fini(&msg->joint);
  // run
  // signal
}

bool
space_interfaces__msg__JointJoggingMsg__are_equal(const space_interfaces__msg__JointJoggingMsg * lhs, const space_interfaces__msg__JointJoggingMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->joint), &(rhs->joint)))
  {
    return false;
  }
  // run
  if (lhs->run != rhs->run) {
    return false;
  }
  // signal
  if (lhs->signal != rhs->signal) {
    return false;
  }
  return true;
}

bool
space_interfaces__msg__JointJoggingMsg__copy(
  const space_interfaces__msg__JointJoggingMsg * input,
  space_interfaces__msg__JointJoggingMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // joint
  if (!rosidl_runtime_c__String__copy(
      &(input->joint), &(output->joint)))
  {
    return false;
  }
  // run
  output->run = input->run;
  // signal
  output->signal = input->signal;
  return true;
}

space_interfaces__msg__JointJoggingMsg *
space_interfaces__msg__JointJoggingMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__JointJoggingMsg * msg = (space_interfaces__msg__JointJoggingMsg *)allocator.allocate(sizeof(space_interfaces__msg__JointJoggingMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(space_interfaces__msg__JointJoggingMsg));
  bool success = space_interfaces__msg__JointJoggingMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
space_interfaces__msg__JointJoggingMsg__destroy(space_interfaces__msg__JointJoggingMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    space_interfaces__msg__JointJoggingMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
space_interfaces__msg__JointJoggingMsg__Sequence__init(space_interfaces__msg__JointJoggingMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__JointJoggingMsg * data = NULL;

  if (size) {
    data = (space_interfaces__msg__JointJoggingMsg *)allocator.zero_allocate(size, sizeof(space_interfaces__msg__JointJoggingMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = space_interfaces__msg__JointJoggingMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        space_interfaces__msg__JointJoggingMsg__fini(&data[i - 1]);
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
space_interfaces__msg__JointJoggingMsg__Sequence__fini(space_interfaces__msg__JointJoggingMsg__Sequence * array)
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
      space_interfaces__msg__JointJoggingMsg__fini(&array->data[i]);
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

space_interfaces__msg__JointJoggingMsg__Sequence *
space_interfaces__msg__JointJoggingMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__msg__JointJoggingMsg__Sequence * array = (space_interfaces__msg__JointJoggingMsg__Sequence *)allocator.allocate(sizeof(space_interfaces__msg__JointJoggingMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = space_interfaces__msg__JointJoggingMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
space_interfaces__msg__JointJoggingMsg__Sequence__destroy(space_interfaces__msg__JointJoggingMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    space_interfaces__msg__JointJoggingMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
space_interfaces__msg__JointJoggingMsg__Sequence__are_equal(const space_interfaces__msg__JointJoggingMsg__Sequence * lhs, const space_interfaces__msg__JointJoggingMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!space_interfaces__msg__JointJoggingMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
space_interfaces__msg__JointJoggingMsg__Sequence__copy(
  const space_interfaces__msg__JointJoggingMsg__Sequence * input,
  space_interfaces__msg__JointJoggingMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(space_interfaces__msg__JointJoggingMsg);
    space_interfaces__msg__JointJoggingMsg * data =
      (space_interfaces__msg__JointJoggingMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!space_interfaces__msg__JointJoggingMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          space_interfaces__msg__JointJoggingMsg__fini(&data[i]);
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
    if (!space_interfaces__msg__JointJoggingMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
