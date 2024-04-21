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

#include "modules/canbus/vehicle/acura_ilx/protocol/car_speed_309.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Carspeed309::Carspeed309() {}
const int32_t Carspeed309::ID = 0x309;

void Carspeed309::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_rough_car_speed(rough_car_speed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_car_speed(car_speed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_rough_car_speed_3(rough_car_speed_3(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_rough_car_speed_2(rough_car_speed_2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_lock_status(lock_status(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_checksum(checksum(bytes, length));
  chassis->mutable_acura_ilx()->mutable_car_speed_309()->set_imperial_unit(imperial_unit(bytes, length));
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 8, 'name': 'rough_car_speed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Carspeed309::rough_car_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'car_speed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Carspeed309::car_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'rough_car_speed_3', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|65535]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
double Carspeed309::rough_car_speed_3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 5);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  double ret = x * 0.010000;
  return ret;
}

// config detail: {'bit': 31, 'is_signed_var': False, 'len': 8, 'name': 'rough_car_speed_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'mph', 'precision': 1.0, 'type': 'int'}
int Carspeed309::rough_car_speed_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 55, 'is_signed_var': False, 'len': 2, 'name': 'lock_status', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Carspeed309::lock_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Carspeed309::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Carspeed309::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 63, 'is_signed_var': False, 'len': 1, 'name': 'imperial_unit', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Carspeed309::imperial_unit(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
