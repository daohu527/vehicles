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

#include "modules/canbus/vehicle/acura_ilx/protocol/brake_pressure_1e7.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Brakepressure1e7::Brakepressure1e7() {}
const int32_t Brakepressure1e7::ID = 0x1E7;

void Brakepressure1e7::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_brake_pressure_1e7()->set_brake_pressure1(brake_pressure1(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_pressure_1e7()->set_brake_pressure2(brake_pressure2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_pressure_1e7()->set_checksum(checksum(bytes, length));
  chassis->mutable_acura_ilx()->mutable_brake_pressure_1e7()->set_counter(counter(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 10, 'name': 'brake_pressure1', 'offset': -103.0, 'order': 'motorola', 'physical_range': '[0|1000]', 'physical_unit': '', 'precision': 0.015625, 'type': 'double'}
double Brakepressure1e7::brake_pressure1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  double ret = x * 0.015625 + -103.000000;
  return ret;
}

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 10, 'name': 'brake_pressure2', 'offset': -103.0, 'order': 'motorola', 'physical_range': '[0|1000]', 'physical_unit': '', 'precision': 0.015625, 'type': 'double'}
double Brakepressure1e7::brake_pressure2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 2);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.015625 + -103.000000;
  return ret;
}

// config detail: {'bit': 27, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakepressure1e7::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 29, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Brakepressure1e7::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
