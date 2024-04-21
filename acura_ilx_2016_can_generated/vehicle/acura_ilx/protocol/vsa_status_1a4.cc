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

#include "modules/canbus/vehicle/acura_ilx/protocol/vsa_status_1a4.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Vsastatus1a4::Vsastatus1a4() {}
const int32_t Vsastatus1a4::ID = 0x1A4;

void Vsastatus1a4::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_user_brake(user_brake(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_computer_braking(computer_braking(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_esp_disabled(esp_disabled(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_brake_hold_related(brake_hold_related(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_brake_hold_active(brake_hold_active(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_brake_hold_enabled(brake_hold_enabled(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vsa_status_1a4()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'user_brake', 'offset': -1.609375, 'order': 'motorola', 'physical_range': '[0|1000]', 'physical_unit': '', 'precision': 0.015625, 'type': 'double'}
double Vsastatus1a4::user_brake(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.015625 + -1.609375;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 1, 'name': 'computer_braking', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vsastatus1a4::computer_braking(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 28, 'is_signed_var': False, 'len': 1, 'name': 'esp_disabled', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vsastatus1a4::esp_disabled(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 52, 'description': 'On when Brake Hold engaged', 'is_signed_var': False, 'len': 1, 'name': 'brake_hold_related', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vsastatus1a4::brake_hold_related(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 46, 'is_signed_var': False, 'len': 1, 'name': 'brake_hold_active', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vsastatus1a4::brake_hold_active(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 45, 'is_signed_var': False, 'len': 1, 'name': 'brake_hold_enabled', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vsastatus1a4::brake_hold_enabled(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vsastatus1a4::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vsastatus1a4::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
