#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "command_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__command_msgs__srv__Command_Request() -> *const std::ffi::c_void;
}

#[link(name = "command_msgs__rosidl_generator_c")]
extern "C" {
    fn command_msgs__srv__Command_Request__init(msg: *mut Command_Request) -> bool;
    fn command_msgs__srv__Command_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Command_Request>, size: usize) -> bool;
    fn command_msgs__srv__Command_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Command_Request>);
    fn command_msgs__srv__Command_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Command_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Command_Request>) -> bool;
}

// Corresponds to command_msgs__srv__Command_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub block_level: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub block_index: i32,

}



impl Default for Command_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !command_msgs__srv__Command_Request__init(&mut msg as *mut _) {
        panic!("Call to command_msgs__srv__Command_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Command_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Command_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Command_Request where Self: Sized {
  const TYPE_NAME: &'static str = "command_msgs/srv/Command_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__command_msgs__srv__Command_Request() }
  }
}


#[link(name = "command_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__command_msgs__srv__Command_Response() -> *const std::ffi::c_void;
}

#[link(name = "command_msgs__rosidl_generator_c")]
extern "C" {
    fn command_msgs__srv__Command_Response__init(msg: *mut Command_Response) -> bool;
    fn command_msgs__srv__Command_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Command_Response>, size: usize) -> bool;
    fn command_msgs__srv__Command_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Command_Response>);
    fn command_msgs__srv__Command_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Command_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Command_Response>) -> bool;
}

// Corresponds to command_msgs__srv__Command_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub done: bool,

}



impl Default for Command_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !command_msgs__srv__Command_Response__init(&mut msg as *mut _) {
        panic!("Call to command_msgs__srv__Command_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Command_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { command_msgs__srv__Command_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Command_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Command_Response where Self: Sized {
  const TYPE_NAME: &'static str = "command_msgs/srv/Command_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__command_msgs__srv__Command_Response() }
  }
}






#[link(name = "command_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__command_msgs__srv__Command() -> *const std::ffi::c_void;
}

// Corresponds to command_msgs__srv__Command
#[allow(missing_docs, non_camel_case_types)]
pub struct Command;

impl rosidl_runtime_rs::Service for Command {
    type Request = Command_Request;
    type Response = Command_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__command_msgs__srv__Command() }
    }
}


