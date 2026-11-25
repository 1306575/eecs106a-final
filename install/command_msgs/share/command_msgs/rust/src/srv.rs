#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to command_msgs__srv__Command_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub command: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub block_level: i32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub block_index: i32,

}



impl Default for Command_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Command_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Command_Request {
  type RmwMsg = super::srv::rmw::Command_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
        block_level: msg.block_level,
        block_index: msg.block_index,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        command: msg.command.as_str().into(),
      block_level: msg.block_level,
      block_index: msg.block_index,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      command: msg.command.to_string(),
      block_level: msg.block_level,
      block_index: msg.block_index,
    }
  }
}


// Corresponds to command_msgs__srv__Command_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Command_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub done: bool,

}



impl Default for Command_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Command_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Command_Response {
  type RmwMsg = super::srv::rmw::Command_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        done: msg.done,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      done: msg.done,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      done: msg.done,
    }
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


