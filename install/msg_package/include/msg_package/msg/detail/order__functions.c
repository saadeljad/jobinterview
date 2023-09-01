// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from msg_package:msg/Order.idl
// generated code does not contain a copyright notice
#include "msg_package/msg/detail/order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

bool
msg_package__msg__Order__init(msg_package__msg__Order * msg)
{
  if (!msg) {
    return false;
  }
  // order_id
  // description
  if (!rosidl_runtime_c__String__init(&msg->description)) {
    msg_package__msg__Order__fini(msg);
    return false;
  }
  return true;
}

void
msg_package__msg__Order__fini(msg_package__msg__Order * msg)
{
  if (!msg) {
    return;
  }
  // order_id
  // description
  rosidl_runtime_c__String__fini(&msg->description);
}

bool
msg_package__msg__Order__are_equal(const msg_package__msg__Order * lhs, const msg_package__msg__Order * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_id
  if (lhs->order_id != rhs->order_id) {
    return false;
  }
  // description
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->description), &(rhs->description)))
  {
    return false;
  }
  return true;
}

bool
msg_package__msg__Order__copy(
  const msg_package__msg__Order * input,
  msg_package__msg__Order * output)
{
  if (!input || !output) {
    return false;
  }
  // order_id
  output->order_id = input->order_id;
  // description
  if (!rosidl_runtime_c__String__copy(
      &(input->description), &(output->description)))
  {
    return false;
  }
  return true;
}

msg_package__msg__Order *
msg_package__msg__Order__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msg_package__msg__Order * msg = (msg_package__msg__Order *)allocator.allocate(sizeof(msg_package__msg__Order), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(msg_package__msg__Order));
  bool success = msg_package__msg__Order__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
msg_package__msg__Order__destroy(msg_package__msg__Order * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    msg_package__msg__Order__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
msg_package__msg__Order__Sequence__init(msg_package__msg__Order__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msg_package__msg__Order * data = NULL;

  if (size) {
    data = (msg_package__msg__Order *)allocator.zero_allocate(size, sizeof(msg_package__msg__Order), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = msg_package__msg__Order__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        msg_package__msg__Order__fini(&data[i - 1]);
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
msg_package__msg__Order__Sequence__fini(msg_package__msg__Order__Sequence * array)
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
      msg_package__msg__Order__fini(&array->data[i]);
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

msg_package__msg__Order__Sequence *
msg_package__msg__Order__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  msg_package__msg__Order__Sequence * array = (msg_package__msg__Order__Sequence *)allocator.allocate(sizeof(msg_package__msg__Order__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = msg_package__msg__Order__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
msg_package__msg__Order__Sequence__destroy(msg_package__msg__Order__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    msg_package__msg__Order__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
msg_package__msg__Order__Sequence__are_equal(const msg_package__msg__Order__Sequence * lhs, const msg_package__msg__Order__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!msg_package__msg__Order__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
msg_package__msg__Order__Sequence__copy(
  const msg_package__msg__Order__Sequence * input,
  msg_package__msg__Order__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(msg_package__msg__Order);
    msg_package__msg__Order * data =
      (msg_package__msg__Order *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!msg_package__msg__Order__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          msg_package__msg__Order__fini(&data[i]);
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
    if (!msg_package__msg__Order__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
