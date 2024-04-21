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

#include "modules/canbus/vehicle/acura_ilx/protocol/powertrain_data_17c.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Powertraindata17c::Powertraindata17c() {}
const int32_t Powertraindata17c::ID = 0x17C;

void Powertraindata17c::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_pedal_gas(pedal_gas(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_engine_rpm(engine_rpm(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_gas_pressed(gas_pressed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_acc_status(acc_status(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_boh_17c(boh_17c(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_brake_switch(brake_switch(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_boh2_17c(boh2_17c(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_brake_pressed(brake_pressed(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_boh3_17c(boh3_17c(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_powertrain_data_17c()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 8, 'name': 'pedal_gas', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::pedal_gas(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'engine_rpm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15000]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::engine_rpm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'is_signed_var': False, 'len': 1, 'name': 'gas_pressed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Powertraindata17c::gas_pressed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 38, 'is_signed_var': False, 'len': 1, 'name': 'acc_status', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Powertraindata17c::acc_status(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 37, 'is_signed_var': False, 'len': 5, 'name': 'boh_17c', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::boh_17c(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(1, 5);

  int ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 1, 'name': 'brake_switch', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Powertraindata17c::brake_switch(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 10, 'name': 'boh2_17c', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::boh2_17c(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 6);
  int32_t t = t1.get_byte(6, 2);
  x <<= 2;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 53, 'is_signed_var': False, 'len': 1, 'name': 'brake_pressed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Powertraindata17c::brake_pressed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 52, 'is_signed_var': False, 'len': 5, 'name': 'boh3_17c', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::boh3_17c(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 5);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Powertraindata17c::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
