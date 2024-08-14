// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from space_interfaces:srv/MultiAxis.idl
// generated code does not contain a copyright notice
#include "space_interfaces/srv/detail/multi_axis__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `goalangle`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
space_interfaces__srv__MultiAxis_Request__init(space_interfaces__srv__MultiAxis_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goalangle
  if (!rosidl_runtime_c__float__Sequence__init(&msg->goalangle, 0)) {
    space_interfaces__srv__MultiAxis_Request__fini(msg);
    return false;
  }
  return true;
}

void
space_interfaces__srv__MultiAxis_Request__fini(space_interfaces__srv__MultiAxis_Request * msg)
{
  if (!msg) {
    return;
  }
  // goalangle
  rosidl_runtime_c__float__Sequence__fini(&msg->goalangle);
}

bool
space_interfaces__srv__MultiAxis_Request__are_equal(const space_interfaces__srv__MultiAxis_Request * lhs, const space_interfaces__srv__MultiAxis_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goalangle
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->goalangle), &(rhs->goalangle)))
  {
    return false;
  }
  return true;
}

bool
space_interfaces__srv__MultiAxis_Request__copy(
  const space_interfaces__srv__MultiAxis_Request * input,
  space_interfaces__srv__MultiAxis_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goalangle
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->goalangle), &(output->goalangle)))
  {
    return false;
  }
  return true;
}

space_interfaces__srv__MultiAxis_Request *
space_interfaces__srv__MultiAxis_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Request * msg = (space_interfaces__srv__MultiAxis_Request *)allocator.allocate(sizeof(space_interfaces__srv__MultiAxis_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(space_interfaces__srv__MultiAxis_Request));
  bool success = space_interfaces__srv__MultiAxis_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
space_interfaces__srv__MultiAxis_Request__destroy(space_interfaces__srv__MultiAxis_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    space_interfaces__srv__MultiAxis_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
space_interfaces__srv__MultiAxis_Request__Sequence__init(space_interfaces__srv__MultiAxis_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Request * data = NULL;

  if (size) {
    data = (space_interfaces__srv__MultiAxis_Request *)allocator.zero_allocate(size, sizeof(space_interfaces__srv__MultiAxis_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = space_interfaces__srv__MultiAxis_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        space_interfaces__srv__MultiAxis_Request__fini(&data[i - 1]);
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
space_interfaces__srv__MultiAxis_Request__Sequence__fini(space_interfaces__srv__MultiAxis_Request__Sequence * array)
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
      space_interfaces__srv__MultiAxis_Request__fini(&array->data[i]);
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

space_interfaces__srv__MultiAxis_Request__Sequence *
space_interfaces__srv__MultiAxis_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Request__Sequence * array = (space_interfaces__srv__MultiAxis_Request__Sequence *)allocator.allocate(sizeof(space_interfaces__srv__MultiAxis_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = space_interfaces__srv__MultiAxis_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
space_interfaces__srv__MultiAxis_Request__Sequence__destroy(space_interfaces__srv__MultiAxis_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    space_interfaces__srv__MultiAxis_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
space_interfaces__srv__MultiAxis_Request__Sequence__are_equal(const space_interfaces__srv__MultiAxis_Request__Sequence * lhs, const space_interfaces__srv__MultiAxis_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!space_interfaces__srv__MultiAxis_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
space_interfaces__srv__MultiAxis_Request__Sequence__copy(
  const space_interfaces__srv__MultiAxis_Request__Sequence * input,
  space_interfaces__srv__MultiAxis_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(space_interfaces__srv__MultiAxis_Request);
    space_interfaces__srv__MultiAxis_Request * data =
      (space_interfaces__srv__MultiAxis_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!space_interfaces__srv__MultiAxis_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          space_interfaces__srv__MultiAxis_Request__fini(&data[i]);
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
    if (!space_interfaces__srv__MultiAxis_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
space_interfaces__srv__MultiAxis_Response__init(space_interfaces__srv__MultiAxis_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    space_interfaces__srv__MultiAxis_Response__fini(msg);
    return false;
  }
  return true;
}

void
space_interfaces__srv__MultiAxis_Response__fini(space_interfaces__srv__MultiAxis_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
space_interfaces__srv__MultiAxis_Response__are_equal(const space_interfaces__srv__MultiAxis_Response * lhs, const space_interfaces__srv__MultiAxis_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
space_interfaces__srv__MultiAxis_Response__copy(
  const space_interfaces__srv__MultiAxis_Response * input,
  space_interfaces__srv__MultiAxis_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

space_interfaces__srv__MultiAxis_Response *
space_interfaces__srv__MultiAxis_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Response * msg = (space_interfaces__srv__MultiAxis_Response *)allocator.allocate(sizeof(space_interfaces__srv__MultiAxis_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(space_interfaces__srv__MultiAxis_Response));
  bool success = space_interfaces__srv__MultiAxis_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
space_interfaces__srv__MultiAxis_Response__destroy(space_interfaces__srv__MultiAxis_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    space_interfaces__srv__MultiAxis_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
space_interfaces__srv__MultiAxis_Response__Sequence__init(space_interfaces__srv__MultiAxis_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Response * data = NULL;

  if (size) {
    data = (space_interfaces__srv__MultiAxis_Response *)allocator.zero_allocate(size, sizeof(space_interfaces__srv__MultiAxis_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = space_interfaces__srv__MultiAxis_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        space_interfaces__srv__MultiAxis_Response__fini(&data[i - 1]);
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
space_interfaces__srv__MultiAxis_Response__Sequence__fini(space_interfaces__srv__MultiAxis_Response__Sequence * array)
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
      space_interfaces__srv__MultiAxis_Response__fini(&array->data[i]);
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

space_interfaces__srv__MultiAxis_Response__Sequence *
space_interfaces__srv__MultiAxis_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  space_interfaces__srv__MultiAxis_Response__Sequence * array = (space_interfaces__srv__MultiAxis_Response__Sequence *)allocator.allocate(sizeof(space_interfaces__srv__MultiAxis_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = space_interfaces__srv__MultiAxis_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
space_interfaces__srv__MultiAxis_Response__Sequence__destroy(space_interfaces__srv__MultiAxis_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    space_interfaces__srv__MultiAxis_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
space_interfaces__srv__MultiAxis_Response__Sequence__are_equal(const space_interfaces__srv__MultiAxis_Response__Sequence * lhs, const space_interfaces__srv__MultiAxis_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!space_interfaces__srv__MultiAxis_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
space_interfaces__srv__MultiAxis_Response__Sequence__copy(
  const space_interfaces__srv__MultiAxis_Response__Sequence * input,
  space_interfaces__srv__MultiAxis_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(space_interfaces__srv__MultiAxis_Response);
    space_interfaces__srv__MultiAxis_Response * data =
      (space_interfaces__srv__MultiAxis_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!space_interfaces__srv__MultiAxis_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          space_interfaces__srv__MultiAxis_Response__fini(&data[i]);
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
    if (!space_interfaces__srv__MultiAxis_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}