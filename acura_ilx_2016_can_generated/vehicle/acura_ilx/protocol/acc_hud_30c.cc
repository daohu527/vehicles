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

#include "modules/canbus/vehicle/acura_ilx/protocol/acc_hud_30c.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Acchud30c::Acchud30c() {}
const int32_t Acchud30c::ID = 0x30C;

void Acchud30c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_pcm_speed(pcm_speed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_pcm_gas(pcm_gas(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_cruise_speed(cruise_speed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_dtc_mode(dtc_mode(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_boh(boh(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_acc_problem(acc_problem(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_fcm_off(fcm_off(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_fcm_off_2(fcm_off_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_fcm_problem(fcm_problem(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_radar_obstructed(radar_obstructed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_enable_mini_car(enable_mini_car(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_hud_distance(hud_distance(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_hud_lead(hud_lead(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_boh_3(boh_3(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_boh_4(boh_4(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_boh_5(boh_5(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_cruise_control_label(cruise_control_label(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_set_me_x01_2(set_me_x01_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_imperial_unit(imperial_unit(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_acc_on(acc_on(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_chime(chime(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_set_me_x01(set_me_x01(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_icons(icons(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_acc_hud_30c()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'description': 'Used by Nidec', 'is_signed_var': False, 'len': 16, 'name': 'pcm_speed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Acchud30c::pcm_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 23, 'description': 'Used by Nidec', 'is_signed_var': False, 'len': 8, 'name': 'pcm_gas', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|127]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::pcm_gas(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 31, 'description': '255 = no speed', 'enum': {252: 'CRUISE_SPEED_STOPPED', 255: 'CRUISE_SPEED_NO_SPEED'}, 'is_signed_var': False, 'len': 8, 'name': 'cruise_speed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'kph', 'precision': 1.0, 'type': 'enum'}
Acc_hud_30c::Cruise_speedType Acchud30c::cruise_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Acc_hud_30c::Cruise_speedType ret =  static_cast<Acc_hud_30c::Cruise_speedType>(x);
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 1, 'name': 'dtc_mode', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::dtc_mode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 38, 'is_signed_var': False, 'len': 1, 'name': 'boh', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::boh(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 37, 'is_signed_var': False, 'len': 1, 'name': 'acc_problem', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::acc_problem(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 1, 'name': 'fcm_off', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::fcm_off(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 1, 'name': 'fcm_off_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::fcm_off_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 34, 'is_signed_var': False, 'len': 1, 'name': 'fcm_problem', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::fcm_problem(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 33, 'is_signed_var': False, 'len': 1, 'name': 'radar_obstructed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::radar_obstructed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 1, 'name': 'enable_mini_car', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::enable_mini_car(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 2, 'name': 'hud_distance', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::hud_distance(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 45, 'enum': {0: 'HUD_LEAD_NO_CAR', 1: 'HUD_LEAD_DASHED_CAR', 2: 'HUD_LEAD_SOLID_CAR', 3: 'HUD_LEAD_NO_CAR'}, 'is_signed_var': False, 'len': 2, 'name': 'hud_lead', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Acc_hud_30c::Hud_leadType Acchud30c::hud_lead(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 2);

  Acc_hud_30c::Hud_leadType ret =  static_cast<Acc_hud_30c::Hud_leadType>(x);
  return ret;
}

// config detail: {'bit': 43, 'is_signed_var': False, 'len': 1, 'name': 'boh_3', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::boh_3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 42, 'is_signed_var': False, 'len': 1, 'name': 'boh_4', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::boh_4(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 41, 'is_signed_var': False, 'len': 1, 'name': 'boh_5', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::boh_5(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 1, 'name': 'cruise_control_label', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::cruise_control_label(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 1, 'name': 'set_me_x01_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::set_me_x01_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 54, 'is_signed_var': False, 'len': 1, 'name': 'imperial_unit', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::imperial_unit(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 52, 'is_signed_var': False, 'len': 1, 'name': 'acc_on', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::acc_on(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 51, 'is_signed_var': False, 'len': 3, 'name': 'chime', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::chime(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(1, 3);

  int ret = x;
  return ret;
}

// config detail: {'bit': 48, 'is_signed_var': False, 'len': 1, 'name': 'set_me_x01', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Acchud30c::set_me_x01(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 2, 'name': 'icons', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::icons(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(6, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Acchud30c::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
