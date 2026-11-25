// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from command_msgs:srv/Command.idl
// generated code does not contain a copyright notice

#ifndef COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_HPP_
#define COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__command_msgs__srv__Command_Request __attribute__((deprecated))
#else
# define DEPRECATED__command_msgs__srv__Command_Request __declspec(deprecated)
#endif

namespace command_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Command_Request_
{
  using Type = Command_Request_<ContainerAllocator>;

  explicit Command_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->block_level = 0l;
      this->block_index = 0l;
    }
  }

  explicit Command_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command = "";
      this->block_level = 0l;
      this->block_index = 0l;
    }
  }

  // field types and members
  using _command_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type command;
  using _block_level_type =
    int32_t;
  _block_level_type block_level;
  using _block_index_type =
    int32_t;
  _block_index_type block_index;

  // setters for named parameter idiom
  Type & set__command(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command = _arg;
    return *this;
  }
  Type & set__block_level(
    const int32_t & _arg)
  {
    this->block_level = _arg;
    return *this;
  }
  Type & set__block_index(
    const int32_t & _arg)
  {
    this->block_index = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    command_msgs::srv::Command_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const command_msgs::srv::Command_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<command_msgs::srv::Command_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<command_msgs::srv::Command_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      command_msgs::srv::Command_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<command_msgs::srv::Command_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      command_msgs::srv::Command_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<command_msgs::srv::Command_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<command_msgs::srv::Command_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<command_msgs::srv::Command_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__command_msgs__srv__Command_Request
    std::shared_ptr<command_msgs::srv::Command_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__command_msgs__srv__Command_Request
    std::shared_ptr<command_msgs::srv::Command_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Command_Request_ & other) const
  {
    if (this->command != other.command) {
      return false;
    }
    if (this->block_level != other.block_level) {
      return false;
    }
    if (this->block_index != other.block_index) {
      return false;
    }
    return true;
  }
  bool operator!=(const Command_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Command_Request_

// alias to use template instance with default allocator
using Command_Request =
  command_msgs::srv::Command_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace command_msgs


#ifndef _WIN32
# define DEPRECATED__command_msgs__srv__Command_Response __attribute__((deprecated))
#else
# define DEPRECATED__command_msgs__srv__Command_Response __declspec(deprecated)
#endif

namespace command_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Command_Response_
{
  using Type = Command_Response_<ContainerAllocator>;

  explicit Command_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->done = false;
    }
  }

  explicit Command_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->done = false;
    }
  }

  // field types and members
  using _done_type =
    bool;
  _done_type done;

  // setters for named parameter idiom
  Type & set__done(
    const bool & _arg)
  {
    this->done = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    command_msgs::srv::Command_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const command_msgs::srv::Command_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<command_msgs::srv::Command_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<command_msgs::srv::Command_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      command_msgs::srv::Command_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<command_msgs::srv::Command_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      command_msgs::srv::Command_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<command_msgs::srv::Command_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<command_msgs::srv::Command_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<command_msgs::srv::Command_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__command_msgs__srv__Command_Response
    std::shared_ptr<command_msgs::srv::Command_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__command_msgs__srv__Command_Response
    std::shared_ptr<command_msgs::srv::Command_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Command_Response_ & other) const
  {
    if (this->done != other.done) {
      return false;
    }
    return true;
  }
  bool operator!=(const Command_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Command_Response_

// alias to use template instance with default allocator
using Command_Response =
  command_msgs::srv::Command_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace command_msgs

namespace command_msgs
{

namespace srv
{

struct Command
{
  using Request = command_msgs::srv::Command_Request;
  using Response = command_msgs::srv::Command_Response;
};

}  // namespace srv

}  // namespace command_msgs

#endif  // COMMAND_MSGS__SRV__DETAIL__COMMAND__STRUCT_HPP_
