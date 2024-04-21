/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

class Brakecommand1fa : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Brakecommand1fa();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 10, 'name': 'COMPUTER_BRAKE', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int computer_brake(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'BRAKE_PUMP_REQUEST', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool brake_pump_request(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'description': 'Used by dual-can Nidec', 'is_signed_var': False, 'len': 1, 'name': 'BRAKE_PUMP_REQUEST_ALT', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool brake_pump_request_alt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 3, 'name': 'SET_ME_X00', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int set_me_x00(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'is_signed_var': False, 'len': 1, 'name': 'CRUISE_OVERRIDE', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool cruise_override(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 1, 'name': 'SET_ME_X00_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool set_me_x00_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'is_signed_var': False, 'len': 1, 'name': 'CRUISE_FAULT_CMD', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool cruise_fault_cmd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 17, 'is_signed_var': False, 'len': 1, 'name': 'CRUISE_CANCEL_CMD', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool cruise_cancel_cmd(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 1, 'name': 'COMPUTER_BRAKE_REQUEST', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool computer_brake_request(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 1, 'name': 'SET_ME_1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool set_me_1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 29, 'description': 'set for duration of suspected AEB event', 'is_signed_var': False, 'len': 1, 'name': 'AEB_REQ_1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool aeb_req_1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 26, 'is_signed_var': False, 'len': 3, 'name': 'AEB_REQ_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int aeb_req_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 1, 'name': 'BRAKE_LIGHTS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool brake_lights(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'is_signed_var': False, 'len': 7, 'name': 'CRUISE_STATES', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int cruise_states(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'enum': {0: 'CHIME_NO_CHIME', 1: 'CHIME_REPEATING_CHIME', 2: 'CHIME_CONTINUOUS_CHIME', 3: 'CHIME_SINGLE_CHIME', 4: 'CHIME_DOUBLE_CHIME'}, 'is_signed_var': False, 'len': 3, 'name': 'CHIME', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brake_command_1fa::ChimeType chime(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 44, 'is_signed_var': False, 'len': 1, 'name': 'SET_ME_X00_3', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool set_me_x00_3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 43, 'enum': {0: 'FCW_NO_FCW', 1: 'FCW_FCW', 2: 'FCW_FCW', 3: 'FCW_FCW'}, 'is_signed_var': False, 'len': 2, 'name': 'FCW', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brake_command_1fa::FcwType fcw(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'enum': {0: 'AEB_STATUS_NO_AEB', 1: 'AEB_STATUS_AEB_BRAKING', 2: 'AEB_STATUS_AEB_READY', 3: 'AEB_STATUS_AEB_PREPARE'}, 'is_signed_var': False, 'len': 2, 'name': 'AEB_STATUS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Brake_command_1fa::Aeb_statusType aeb_status(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'description': 'Used by dual-can Nidec', 'is_signed_var': False, 'len': 10, 'name': 'COMPUTER_BRAKE_ALT', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int computer_brake_alt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


