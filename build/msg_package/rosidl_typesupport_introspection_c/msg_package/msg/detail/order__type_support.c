// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from msg_package:msg/Order.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "msg_package/msg/detail/order__rosidl_typesupport_introspection_c.h"
#include "msg_package/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "msg_package/msg/detail/order__functions.h"
#include "msg_package/msg/detail/order__struct.h"


// Include directives for member types
// Member `description`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Order__rosidl_typesupport_introspection_c__Order_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  msg_package__msg__Order__init(message_memory);
}

void Order__rosidl_typesupport_introspection_c__Order_fini_function(void * message_memory)
{
  msg_package__msg__Order__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Order__rosidl_typesupport_introspection_c__Order_message_member_array[2] = {
  {
    "order_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msg_package__msg__Order, order_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "description",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(msg_package__msg__Order, description),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Order__rosidl_typesupport_introspection_c__Order_message_members = {
  "msg_package__msg",  // message namespace
  "Order",  // message name
  2,  // number of fields
  sizeof(msg_package__msg__Order),
  Order__rosidl_typesupport_introspection_c__Order_message_member_array,  // message members
  Order__rosidl_typesupport_introspection_c__Order_init_function,  // function to initialize message memory (memory has to be allocated)
  Order__rosidl_typesupport_introspection_c__Order_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle = {
  0,
  &Order__rosidl_typesupport_introspection_c__Order_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_msg_package
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, msg_package, msg, Order)() {
  if (!Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle.typesupport_identifier) {
    Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Order__rosidl_typesupport_introspection_c__Order_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
