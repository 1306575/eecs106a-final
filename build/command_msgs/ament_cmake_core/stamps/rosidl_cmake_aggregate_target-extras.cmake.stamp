# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target command_msgs::command_msgs
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${command_msgs_TARGETS}.
if(command_msgs_TARGETS AND NOT TARGET command_msgs::command_msgs)
  add_library(command_msgs::command_msgs INTERFACE IMPORTED)
  set_target_properties(command_msgs::command_msgs PROPERTIES
    INTERFACE_LINK_LIBRARIES "${command_msgs_TARGETS}")
endif()
