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

#include "modules/canbus/vehicle/acura_ilx/protocol/steering_control_e4.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Steeringcontrole4::Steeringcontrole4() {}
const int32_t Steeringcontrole4::ID = 0xE4;

void Steeringcontrole4::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_steering_control_e4()->set_steer_torque(steer_torque(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steering_control_e4()->set_steer_torque_request(steer_torque_request(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steering_control_e4()->set_set_me_x00(set_me_x00(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steering_control_e4()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steering_control_e4()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': True, 'len': 16, 'name': 'steer_torque', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-3840|3840]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringcontrole4::steer_torque(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 1, 'name': 'steer_torque_request', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Steeringcontrole4::steer_torque_request(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 8, 'name': 'set_me_x00', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringcontrole4::set_me_x00(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 37, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringcontrole4::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steeringcontrole4::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
