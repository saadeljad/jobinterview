// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from msg_package:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef MSG_PACKAGE__MSG__DETAIL__ORDER__STRUCT_H_
#define MSG_PACKAGE__MSG__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'description'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/Order in the package msg_package.
typedef struct msg_package__msg__Order
{
  uint32_t order_id;
  rosidl_runtime_c__String description;
} msg_package__msg__Order;

// Struct for a sequence of msg_package__msg__Order.
typedef struct msg_package__msg__Order__Sequence
{
  msg_package__msg__Order * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} msg_package__msg__Order__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MSG_PACKAGE__MSG__DETAIL__ORDER__STRUCT_H_
