// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from command_msgs:srv/Command.idl
// generated code does not contain a copyright notice
#include "command_msgs/srv/detail/command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `command`
#include "rosidl_runtime_c/string_functions.h"

bool
command_msgs__srv__Command_Request__init(command_msgs__srv__Command_Request * msg)
{
  if (!msg) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__init(&msg->command)) {
    command_msgs__srv__Command_Request__fini(msg);
    return false;
  }
  // block_level
  // block_index
  return true;
}

void
command_msgs__srv__Command_Request__fini(command_msgs__srv__Command_Request * msg)
{
  if (!msg) {
    return;
  }
  // command
  rosidl_runtime_c__String__fini(&msg->command);
  // block_level
  // block_index
}

bool
command_msgs__srv__Command_Request__are_equal(const command_msgs__srv__Command_Request * lhs, const command_msgs__srv__Command_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command), &(rhs->command)))
  {
    return false;
  }
  // block_level
  if (lhs->block_level != rhs->block_level) {
    return false;
  }
  // block_index
  if (lhs->block_index != rhs->block_index) {
    return false;
  }
  return true;
}

bool
command_msgs__srv__Command_Request__copy(
  const command_msgs__srv__Command_Request * input,
  command_msgs__srv__Command_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // command
  if (!rosidl_runtime_c__String__copy(
      &(input->command), &(output->command)))
  {
    return false;
  }
  // block_level
  output->block_level = input->block_level;
  // block_index
  output->block_index = input->block_index;
  return true;
}

command_msgs__srv__Command_Request *
command_msgs__srv__Command_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Request * msg = (command_msgs__srv__Command_Request *)allocator.allocate(sizeof(command_msgs__srv__Command_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(command_msgs__srv__Command_Request));
  bool success = command_msgs__srv__Command_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
command_msgs__srv__Command_Request__destroy(command_msgs__srv__Command_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    command_msgs__srv__Command_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
command_msgs__srv__Command_Request__Sequence__init(command_msgs__srv__Command_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Request * data = NULL;

  if (size) {
    data = (command_msgs__srv__Command_Request *)allocator.zero_allocate(size, sizeof(command_msgs__srv__Command_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = command_msgs__srv__Command_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        command_msgs__srv__Command_Request__fini(&data[i - 1]);
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
command_msgs__srv__Command_Request__Sequence__fini(command_msgs__srv__Command_Request__Sequence * array)
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
      command_msgs__srv__Command_Request__fini(&array->data[i]);
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

command_msgs__srv__Command_Request__Sequence *
command_msgs__srv__Command_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Request__Sequence * array = (command_msgs__srv__Command_Request__Sequence *)allocator.allocate(sizeof(command_msgs__srv__Command_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = command_msgs__srv__Command_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
command_msgs__srv__Command_Request__Sequence__destroy(command_msgs__srv__Command_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    command_msgs__srv__Command_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
command_msgs__srv__Command_Request__Sequence__are_equal(const command_msgs__srv__Command_Request__Sequence * lhs, const command_msgs__srv__Command_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!command_msgs__srv__Command_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
command_msgs__srv__Command_Request__Sequence__copy(
  const command_msgs__srv__Command_Request__Sequence * input,
  command_msgs__srv__Command_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(command_msgs__srv__Command_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    command_msgs__srv__Command_Request * data =
      (command_msgs__srv__Command_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!command_msgs__srv__Command_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          command_msgs__srv__Command_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!command_msgs__srv__Command_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
command_msgs__srv__Command_Response__init(command_msgs__srv__Command_Response * msg)
{
  if (!msg) {
    return false;
  }
  // done
  return true;
}

void
command_msgs__srv__Command_Response__fini(command_msgs__srv__Command_Response * msg)
{
  if (!msg) {
    return;
  }
  // done
}

bool
command_msgs__srv__Command_Response__are_equal(const command_msgs__srv__Command_Response * lhs, const command_msgs__srv__Command_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // done
  if (lhs->done != rhs->done) {
    return false;
  }
  return true;
}

bool
command_msgs__srv__Command_Response__copy(
  const command_msgs__srv__Command_Response * input,
  command_msgs__srv__Command_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // done
  output->done = input->done;
  return true;
}

command_msgs__srv__Command_Response *
command_msgs__srv__Command_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Response * msg = (command_msgs__srv__Command_Response *)allocator.allocate(sizeof(command_msgs__srv__Command_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(command_msgs__srv__Command_Response));
  bool success = command_msgs__srv__Command_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
command_msgs__srv__Command_Response__destroy(command_msgs__srv__Command_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    command_msgs__srv__Command_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
command_msgs__srv__Command_Response__Sequence__init(command_msgs__srv__Command_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Response * data = NULL;

  if (size) {
    data = (command_msgs__srv__Command_Response *)allocator.zero_allocate(size, sizeof(command_msgs__srv__Command_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = command_msgs__srv__Command_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        command_msgs__srv__Command_Response__fini(&data[i - 1]);
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
command_msgs__srv__Command_Response__Sequence__fini(command_msgs__srv__Command_Response__Sequence * array)
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
      command_msgs__srv__Command_Response__fini(&array->data[i]);
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

command_msgs__srv__Command_Response__Sequence *
command_msgs__srv__Command_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  command_msgs__srv__Command_Response__Sequence * array = (command_msgs__srv__Command_Response__Sequence *)allocator.allocate(sizeof(command_msgs__srv__Command_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = command_msgs__srv__Command_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
command_msgs__srv__Command_Response__Sequence__destroy(command_msgs__srv__Command_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    command_msgs__srv__Command_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
command_msgs__srv__Command_Response__Sequence__are_equal(const command_msgs__srv__Command_Response__Sequence * lhs, const command_msgs__srv__Command_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!command_msgs__srv__Command_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
command_msgs__srv__Command_Response__Sequence__copy(
  const command_msgs__srv__Command_Response__Sequence * input,
  command_msgs__srv__Command_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(command_msgs__srv__Command_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    command_msgs__srv__Command_Response * data =
      (command_msgs__srv__Command_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!command_msgs__srv__Command_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          command_msgs__srv__Command_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!command_msgs__srv__Command_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
