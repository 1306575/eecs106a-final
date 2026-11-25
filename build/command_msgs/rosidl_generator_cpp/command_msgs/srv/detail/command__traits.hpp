// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from command_msgs:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMAND_MSGS__SRV__DETAIL__COMMAND__TRAITS_HPP_
#define COMMAND_MSGS__SRV__DETAIL__COMMAND__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "command_msgs/srv/detail/command__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace command_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Command_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: command
  {
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << ", ";
  }

  // member: block_level
  {
    out << "block_level: ";
    rosidl_generator_traits::value_to_yaml(msg.block_level, out);
    out << ", ";
  }

  // member: block_index
  {
    out << "block_index: ";
    rosidl_generator_traits::value_to_yaml(msg.block_index, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Command_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: command
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command: ";
    rosidl_generator_traits::value_to_yaml(msg.command, out);
    out << "\n";
  }

  // member: block_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "block_level: ";
    rosidl_generator_traits::value_to_yaml(msg.block_level, out);
    out << "\n";
  }

  // member: block_index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "block_index: ";
    rosidl_generator_traits::value_to_yaml(msg.block_index, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Command_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace command_msgs

namespace rosidl_generator_traits
{

[[deprecated("use command_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const command_msgs::srv::Command_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  command_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use command_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const command_msgs::srv::Command_Request & msg)
{
  return command_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<command_msgs::srv::Command_Request>()
{
  return "command_msgs::srv::Command_Request";
}

template<>
inline const char * name<command_msgs::srv::Command_Request>()
{
  return "command_msgs/srv/Command_Request";
}

template<>
struct has_fixed_size<command_msgs::srv::Command_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<command_msgs::srv::Command_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<command_msgs::srv::Command_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace command_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Command_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: done
  {
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Command_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: done
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "done: ";
    rosidl_generator_traits::value_to_yaml(msg.done, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Command_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace command_msgs

namespace rosidl_generator_traits
{

[[deprecated("use command_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const command_msgs::srv::Command_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  command_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use command_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const command_msgs::srv::Command_Response & msg)
{
  return command_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<command_msgs::srv::Command_Response>()
{
  return "command_msgs::srv::Command_Response";
}

template<>
inline const char * name<command_msgs::srv::Command_Response>()
{
  return "command_msgs/srv/Command_Response";
}

template<>
struct has_fixed_size<command_msgs::srv::Command_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<command_msgs::srv::Command_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<command_msgs::srv::Command_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<command_msgs::srv::Command>()
{
  return "command_msgs::srv::Command";
}

template<>
inline const char * name<command_msgs::srv::Command>()
{
  return "command_msgs/srv/Command";
}

template<>
struct has_fixed_size<command_msgs::srv::Command>
  : std::integral_constant<
    bool,
    has_fixed_size<command_msgs::srv::Command_Request>::value &&
    has_fixed_size<command_msgs::srv::Command_Response>::value
  >
{
};

template<>
struct has_bounded_size<command_msgs::srv::Command>
  : std::integral_constant<
    bool,
    has_bounded_size<command_msgs::srv::Command_Request>::value &&
    has_bounded_size<command_msgs::srv::Command_Response>::value
  >
{
};

template<>
struct is_service<command_msgs::srv::Command>
  : std::true_type
{
};

template<>
struct is_service_request<command_msgs::srv::Command_Request>
  : std::true_type
{
};

template<>
struct is_service_response<command_msgs::srv::Command_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // COMMAND_MSGS__SRV__DETAIL__COMMAND__TRAITS_HPP_
