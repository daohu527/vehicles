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

#include "modules/canbus/vehicle/acura_ilx/protocol/vehicle_dynamics_1ea.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Vehicledynamics1ea::Vehicledynamics1ea() {}
const int32_t Vehicledynamics1ea::ID = 0x1EA;

void Vehicledynamics1ea::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_vehicle_dynamics_1ea()->set_lat_accel(lat_accel(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vehicle_dynamics_1ea()->set_long_accel(long_accel(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vehicle_dynamics_1ea()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_vehicle_dynamics_1ea()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': True, 'len': 16, 'name': 'lat_accel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-20|20]', 'physical_unit': 'm/s2', 'precision': 0.0015, 'type': 'double'}
double Vehicledynamics1ea::lat_accel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * 0.001500;
  return ret;
}

// config detail: {'bit': 23, 'description': 'wheel speed derivative, noisy and zero snapping', 'is_signed_var': True, 'len': 16, 'name': 'long_accel', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-20|20]', 'physical_unit': 'm/s2', 'precision': 0.0015, 'type': 'double'}
double Vehicledynamics1ea::long_accel(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 16;
  x >>= 16;

  double ret = x * 0.001500;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vehicledynamics1ea::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vehicledynamics1ea::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
