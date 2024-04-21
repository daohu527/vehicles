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

#include "modules/canbus/vehicle/acura_ilx/protocol/lkas_hud_33d.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Lkashud33d::Lkashud33d() {}
const int32_t Lkashud33d::ID = 0x33D;

void Lkashud33d::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_cam_temp_high(cam_temp_high(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_set_me_x41(set_me_x41(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_boh(boh(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_dashed_lanes(dashed_lanes(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_dtc(dtc(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_lkas_problem(lkas_problem(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_lkas_off(lkas_off(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_solid_lanes(solid_lanes(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_ldw_right(ldw_right(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_steering_required(steering_required(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_boh_2(boh_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_ldw_problem(ldw_problem(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_beep(beep(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_ldw_on(ldw_on(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_ldw_off(ldw_off(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_clean_windshield(clean_windshield(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_set_me_x48(set_me_x48(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_lkas_hud_33d()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'cam_temp_high', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::cam_temp_high(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 7, 'name': 'set_me_x41', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|127]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::set_me_x41(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 7);

  int ret = x;
  return ret;
}

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 7, 'name': 'boh', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|127]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::boh(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 7);

  int ret = x;
  return ret;
}

// config detail: {'bit': 14, 'is_signed_var': False, 'len': 1, 'name': 'dashed_lanes', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::dashed_lanes(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 13, 'is_signed_var': False, 'len': 1, 'name': 'dtc', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::dtc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'lkas_problem', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::lkas_problem(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'lkas_off', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::lkas_off(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'solid_lanes', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::solid_lanes(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'ldw_right', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::ldw_right(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'steering_required', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::steering_required(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 2, 'name': 'boh_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|4]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::boh_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(6, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 21, 'is_signed_var': False, 'len': 1, 'name': 'ldw_problem', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::ldw_problem(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 17, 'description': 'beeps are pleasant, chimes are for warnngs etc...', 'enum': {0: 'BEEP_NO_BEEP', 1: 'BEEP_REPEATED_BEEP', 2: 'BEEP_TRIPLE_BEEP', 3: 'BEEP_SINGLE_BEEP'}, 'is_signed_var': False, 'len': 2, 'name': 'beep', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Lkas_hud_33d::BeepType Lkashud33d::beep(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 2);

  Lkas_hud_33d::BeepType ret =  static_cast<Lkas_hud_33d::BeepType>(x);
  return ret;
}

// config detail: {'bit': 28, 'is_signed_var': False, 'len': 1, 'name': 'ldw_on', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::ldw_on(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 27, 'is_signed_var': False, 'len': 1, 'name': 'ldw_off', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::ldw_off(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 26, 'is_signed_var': False, 'len': 1, 'name': 'clean_windshield', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Lkashud33d::clean_windshield(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 8, 'name': 'set_me_x48', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::set_me_x48(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 37, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Lkashud33d::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
