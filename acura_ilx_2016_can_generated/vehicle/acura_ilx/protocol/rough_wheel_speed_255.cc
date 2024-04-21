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

#include "modules/canbus/vehicle/acura_ilx/protocol/rough_wheel_speed_255.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Roughwheelspeed255::Roughwheelspeed255() {}
const int32_t Roughwheelspeed255::ID = 0x255;

void Roughwheelspeed255::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_wheel_speed_fl(wheel_speed_fl(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_wheel_speed_fr(wheel_speed_fr(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_wheel_speed_rl(wheel_speed_rl(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_wheel_speed_rr(wheel_speed_rr(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_set_to_x55(set_to_x55(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_set_to_x55_2(set_to_x55_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_rough_wheel_speed_255()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'wheel_speed_fl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::wheel_speed_fl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 8, 'name': 'wheel_speed_fr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::wheel_speed_fr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'wheel_speed_rl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::wheel_speed_rl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 8, 'name': 'wheel_speed_rr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::wheel_speed_rr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 8, 'name': 'set_to_x55', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::set_to_x55(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 8, 'name': 'set_to_x55_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::set_to_x55_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Roughwheelspeed255::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
