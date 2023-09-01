// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from msg_package:msg/Order.idl
// generated code does not contain a copyright notice

#ifndef MSG_PACKAGE__MSG__DETAIL__ORDER__BUILDER_HPP_
#define MSG_PACKAGE__MSG__DETAIL__ORDER__BUILDER_HPP_

#include "msg_package/msg/detail/order__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace msg_package
{

namespace msg
{

namespace builder
{

class Init_Order_description
{
public:
  explicit Init_Order_description(::msg_package::msg::Order & msg)
  : msg_(msg)
  {}
  ::msg_package::msg::Order description(::msg_package::msg::Order::_description_type arg)
  {
    msg_.description = std::move(arg);
    return std::move(msg_);
  }

private:
  ::msg_package::msg::Order msg_;
};

class Init_Order_order_id
{
public:
  Init_Order_order_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_description order_id(::msg_package::msg::Order::_order_id_type arg)
  {
    msg_.order_id = std::move(arg);
    return Init_Order_description(msg_);
  }

private:
  ::msg_package::msg::Order msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::msg_package::msg::Order>()
{
  return msg_package::msg::builder::Init_Order_order_id();
}

}  // namespace msg_package

#endif  // MSG_PACKAGE__MSG__DETAIL__ORDER__BUILDER_HPP_
