// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from command_msgs:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_
#define COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'command'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Command in the package command_msgs.
typedef struct command_msgs__srv__Command_Request
{
  rosidl_runtime_c__String command;
  int32_t block_level;
  int32_t block_index;
} command_msgs__srv__Command_Request;

// Struct for a sequence of command_msgs__srv__Command_Request.
typedef struct command_msgs__srv__Command_Request__Sequence
{
  command_msgs__srv__Command_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} command_msgs__srv__Command_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Command in the package command_msgs.
typedef struct command_msgs__srv__Command_Response
{
  bool done;
} command_msgs__srv__Command_Response;

// Struct for a sequence of command_msgs__srv__Command_Response.
typedef struct command_msgs__srv__Command_Response__Sequence
{
  command_msgs__srv__Command_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} command_msgs__srv__Command_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_H_
