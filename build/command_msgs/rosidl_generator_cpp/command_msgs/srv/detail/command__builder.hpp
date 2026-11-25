// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from command_msgs:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMAND_MSGS__SRV__DETAIL__COMMAND__BUILDER_HPP_
#define COMMAND_MSGS__SRV__DETAIL__COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "command_msgs/srv/detail/command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace command_msgs
{

namespace srv
{

namespace builder
{

class Init_Command_Request_block_index
{
public:
  explicit Init_Command_Request_block_index(::command_msgs::srv::Command_Request & msg)
  : msg_(msg)
  {}
  ::command_msgs::srv::Command_Request block_index(::command_msgs::srv::Command_Request::_block_index_type arg)
  {
    msg_.block_index = std::move(arg);
    return std::move(msg_);
  }

private:
  ::command_msgs::srv::Command_Request msg_;
};

class Init_Command_Request_block_level
{
public:
  explicit Init_Command_Request_block_level(::command_msgs::srv::Command_Request & msg)
  : msg_(msg)
  {}
  Init_Command_Request_block_index block_level(::command_msgs::srv::Command_Request::_block_level_type arg)
  {
    msg_.block_level = std::move(arg);
    return Init_Command_Request_block_index(msg_);
  }

private:
  ::command_msgs::srv::Command_Request msg_;
};

class Init_Command_Request_command
{
public:
  Init_Command_Request_command()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Command_Request_block_level command(::command_msgs::srv::Command_Request::_command_type arg)
  {
    msg_.command = std::move(arg);
    return Init_Command_Request_block_level(msg_);
  }

private:
  ::command_msgs::srv::Command_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::command_msgs::srv::Command_Request>()
{
  return command_msgs::srv::builder::Init_Command_Request_command();
}

}  // namespace command_msgs


namespace command_msgs
{

namespace srv
{

namespace builder
{

class Init_Command_Response_done
{
public:
  Init_Command_Response_done()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::command_msgs::srv::Command_Response done(::command_msgs::srv::Command_Response::_done_type arg)
  {
    msg_.done = std::move(arg);
    return std::move(msg_);
  }

private:
  ::command_msgs::srv::Command_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::command_msgs::srv::Command_Response>()
{
  return command_msgs::srv::builder::Init_Command_Response_done();
}

}  // namespace command_msgs

#endif  // COMMAND_MSGS__SRV__DETAIL__COMMAND__BUILDER_HPP_
