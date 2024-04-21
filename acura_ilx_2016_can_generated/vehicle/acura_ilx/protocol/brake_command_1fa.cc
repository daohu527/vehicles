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

#include "modules/canbus/vehicle/acura_ilx/protocol/brake_command_1fa.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Brakecommand1fa::Brakecommand1fa() {}
const int32_t Brakecommand1fa::ID = 0x1FA;

void Brakecommand1fa::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_computer_brake(computer_brake(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_brake_pump_request(brake_pump_request(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_brake_pump_request_alt(brake_pump_request_alt(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_set_me_x00(set_me_x00(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_cruise_override(cruise_override(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_set_me_x00_2(set_me_x00_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_cruise_fault_cmd(cruise_fault_cmd(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_cruise_cancel_cmd(cruise_cancel_cmd(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_computer_brake_request(computer_brake_request(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_set_me_1(set_me_1(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_aeb_req_1(aeb_req_1(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_aeb_req_2(aeb_req_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_brake_lights(brake_lights(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_cruise_states(cruise_states(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_chime(chime(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_set_me_x00_3(set_me_x00_3(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_fcw(fcw(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_aeb_status(aeb_status(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_computer_brake_alt(computer_brake_alt(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_command_1fa()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 10, 'name': 'computer_brake', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::computer_brake(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'brake_pump_request', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::brake_pump_request(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 11, 'description': 'Used by dual-can Nidec', 'is_signed_var': False, 'len': 1, 'name': 'brake_pump_request_alt', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::brake_pump_request_alt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 3, 'name': 'set_me_x00', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::set_me_x00(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 20, 'is_signed_var': False, 'len': 1, 'name': 'cruise_override', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::cruise_override(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 1, 'name': 'set_me_x00_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::set_me_x00_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 18, 'is_signed_var': False, 'len': 1, 'name': 'cruise_fault_cmd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::cruise_fault_cmd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 17, 'is_signed_var': False, 'len': 1, 'name': 'cruise_cancel_cmd', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::cruise_cancel_cmd(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 1, 'name': 'computer_brake_request', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::computer_brake_request(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 1, 'name': 'set_me_1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::set_me_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 29, 'description': 'set for duration of suspected AEB event', 'is_signed_var': False, 'len': 1, 'name': 'aeb_req_1', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::aeb_req_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 26, 'is_signed_var': False, 'len': 3, 'name': 'aeb_req_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::aeb_req_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 1, 'name': 'brake_lights', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::brake_lights(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 38, 'is_signed_var': False, 'len': 7, 'name': 'cruise_states', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::cruise_states(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 7);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'enum': {0: 'CHIME_NO_CHIME', 1: 'CHIME_REPEATING_CHIME', 2: 'CHIME_CONTINUOUS_CHIME', 3: 'CHIME_SINGLE_CHIME', 4: 'CHIME_DOUBLE_CHIME'}, 'is_signed_var': False, 'len': 3, 'name': 'chime', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_command_1fa::ChimeType Brakecommand1fa::chime(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 3);

  Brake_command_1fa::ChimeType ret =  static_cast<Brake_command_1fa::ChimeType>(x);
  return ret;
}

// config detail: {'bit': 44, 'is_signed_var': False, 'len': 1, 'name': 'set_me_x00_3', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Brakecommand1fa::set_me_x00_3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 43, 'enum': {0: 'FCW_NO_FCW', 1: 'FCW_FCW', 2: 'FCW_FCW', 3: 'FCW_FCW'}, 'is_signed_var': False, 'len': 2, 'name': 'fcw', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_command_1fa::FcwType Brakecommand1fa::fcw(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 2);

  Brake_command_1fa::FcwType ret =  static_cast<Brake_command_1fa::FcwType>(x);
  return ret;
}

// config detail: {'bit': 41, 'enum': {0: 'AEB_STATUS_NO_AEB', 1: 'AEB_STATUS_AEB_BRAKING', 2: 'AEB_STATUS_AEB_READY', 3: 'AEB_STATUS_AEB_PREPARE'}, 'is_signed_var': False, 'len': 2, 'name': 'aeb_status', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Brake_command_1fa::Aeb_statusType Brakecommand1fa::aeb_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  Brake_command_1fa::Aeb_statusType ret =  static_cast<Brake_command_1fa::Aeb_statusType>(x);
  return ret;
}

// config detail: {'bit': 55, 'description': 'Used by dual-can Nidec', 'is_signed_var': False, 'len': 10, 'name': 'computer_brake_alt', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::computer_brake_alt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 7);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakecommand1fa::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
