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

#include "modules/canbus/vehicle/acura_ilx/protocol/gearbox_1a3.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Gearbox1a3::Gearbox1a3() {}
const int32_t Gearbox1a3::ID = 0x1A3;

void Gearbox1a3::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_gearbox_1a3()->set_gear(gear(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gearbox_1a3()->set_gear_shifter(gear_shifter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gearbox_1a3()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gearbox_1a3()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'description': '10 = reverse, 11 = transition', 'is_signed_var': False, 'len': 8, 'name': 'gear', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|256]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gearbox1a3::gear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 35, 'enum': {1: 'GEAR_SHIFTER_P', 2: 'GEAR_SHIFTER_R', 3: 'GEAR_SHIFTER_N', 4: 'GEAR_SHIFTER_D', 10: 'GEAR_SHIFTER_S'}, 'is_signed_var': False, 'len': 4, 'name': 'gear_shifter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Gearbox_1a3::Gear_shifterType Gearbox1a3::gear_shifter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  Gearbox_1a3::Gear_shifterType ret =  static_cast<Gearbox_1a3::Gear_shifterType>(x);
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gearbox1a3::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gearbox1a3::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
