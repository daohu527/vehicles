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

#include "modules/canbus/vehicle/acura_ilx/protocol/steer_status_18f.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Steerstatus18f::Steerstatus18f() {}
const int32_t Steerstatus18f::ID = 0x18F;

void Steerstatus18f::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_steer_torque_sensor(steer_torque_sensor(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_steer_angle_rate(steer_angle_rate(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_steer_status(steer_status(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_steer_control_active(steer_control_active(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_steer_config_index(steer_config_index(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_steer_status_18f()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': True, 'len': 16, 'name': 'steer_torque_sensor', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-31000|31000]', 'physical_unit': 'tbd', 'precision': -1.0, 'type': 'double'}
double Steerstatus18f::steer_torque_sensor(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * -1.000000;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': True, 'len': 16, 'name': 'steer_angle_rate', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-31000|31000]', 'physical_unit': 'deg/s', 'precision': -0.1, 'type': 'double'}
double Steerstatus18f::steer_angle_rate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * -0.100000;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'STEER_STATUS_NORMAL', 2: 'STEER_STATUS_NO_TORQUE_ALERT_1', 3: 'STEER_STATUS_LOW_SPEED_LOCKOUT', 4: 'STEER_STATUS_NO_TORQUE_ALERT_2', 5: 'STEER_STATUS_FAULT_1', 6: 'STEER_STATUS_TMP_FAULT'}, 'is_signed_var': False, 'len': 4, 'name': 'steer_status', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Steer_status_18f::Steer_statusType Steerstatus18f::steer_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 4);

  Steer_status_18f::Steer_statusType ret =  static_cast<Steer_status_18f::Steer_statusType>(x);
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 1, 'name': 'steer_control_active', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Steerstatus18f::steer_control_active(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 43, 'is_signed_var': False, 'len': 4, 'name': 'steer_config_index', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steerstatus18f::steer_config_index(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 53, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steerstatus18f::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 51, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Steerstatus18f::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
