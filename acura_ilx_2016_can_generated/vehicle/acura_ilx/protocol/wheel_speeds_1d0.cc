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

#include "modules/canbus/vehicle/acura_ilx/protocol/wheel_speeds_1d0.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Wheelspeeds1d0::Wheelspeeds1d0() {}
const int32_t Wheelspeeds1d0::ID = 0x1D0;

void Wheelspeeds1d0::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_wheel_speeds_1d0()->set_wheel_speed_fl(wheel_speed_fl(bytes, length));
  chassis->mutable_acura_ilx()->mutable_wheel_speeds_1d0()->set_wheel_speed_fr(wheel_speed_fr(bytes, length));
  chassis->mutable_acura_ilx()->mutable_wheel_speeds_1d0()->set_wheel_speed_rl(wheel_speed_rl(bytes, length));
  chassis->mutable_acura_ilx()->mutable_wheel_speeds_1d0()->set_wheel_speed_rr(wheel_speed_rr(bytes, length));
  chassis->mutable_acura_ilx()->mutable_wheel_speeds_1d0()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 15, 'name': 'wheel_speed_fl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Wheelspeeds1d0::wheel_speed_fl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(1, 7);
  x <<= 7;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 15, 'name': 'wheel_speed_fr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Wheelspeeds1d0::wheel_speed_fr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 3);
  t = t2.get_byte(2, 6);
  x <<= 6;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 25, 'is_signed_var': False, 'len': 15, 'name': 'wheel_speed_rl', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Wheelspeeds1d0::wheel_speed_rl(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 2);

  Byte t1(bytes + 4);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 5);
  t = t2.get_byte(3, 5);
  x <<= 5;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 42, 'is_signed_var': False, 'len': 15, 'name': 'wheel_speed_rr', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Wheelspeeds1d0::wheel_speed_rr(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 3);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  Byte t2(bytes + 7);
  t = t2.get_byte(4, 4);
  x <<= 4;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Wheelspeeds1d0::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
