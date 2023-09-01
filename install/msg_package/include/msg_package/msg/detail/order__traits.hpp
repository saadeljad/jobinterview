// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from msg_package:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef MSG_PACKAGE__MSG__DETAIL__ORDER__TRAITS_HPP_
#define MSG_PACKAGE__MSG__DETAIL__ORDER__TRAITS_HPP_

#include "msg_package/msg/detail/order__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<msg_package::msg::Order>()
{
  return "msg_package::msg::Order";
}

template<>
inline const char * name<msg_package::msg::Order>()
{
  return "msg_package/msg/Order";
}

template<>
struct has_fixed_size<msg_package::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<msg_package::msg::Order>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<msg_package::msg::Order>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // MSG_PACKAGE__MSG__DETAIL__ORDER__TRAITS_HPP_
