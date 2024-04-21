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

#include "modules/canbus/vehicle/acura_ilx/protocol/stalk_status_2_37b.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Stalkstatus237b::Stalkstatus237b() {}
const int32_t Stalkstatus237b::ID = 0x37B;

void Stalkstatus237b::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_wipers(wipers(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_low_beams(low_beams(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_high_beams(high_beams(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_park_lights(park_lights(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_2_37b()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 17, 'enum': {0: 'WIPERS_OFF', 2: 'WIPERS_LOW', 4: 'WIPERS_HIGH'}, 'is_signed_var': False, 'len': 2, 'name': 'wipers', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Stalk_status_2_37b::WipersType Stalkstatus237b::wipers(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 2);

  Stalk_status_2_37b::WipersType ret =  static_cast<Stalk_status_2_37b::WipersType>(x);
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 1, 'name': 'low_beams', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus237b::low_beams(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 34, 'is_signed_var': False, 'len': 1, 'name': 'high_beams', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus237b::high_beams(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 36, 'is_signed_var': False, 'len': 1, 'name': 'park_lights', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus237b::park_lights(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Stalkstatus237b::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Stalkstatus237b::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
