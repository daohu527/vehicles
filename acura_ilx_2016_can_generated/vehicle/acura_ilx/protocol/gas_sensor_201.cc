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

#include "modules/canbus/vehicle/acura_ilx/protocol/gas_sensor_201.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Gassensor201::Gassensor201() {}
const int32_t Gassensor201::ID = 0x201;

void Gassensor201::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_gas_sensor_201()->set_interceptor_gas(interceptor_gas(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gas_sensor_201()->set_interceptor_gas2(interceptor_gas2(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gas_sensor_201()->set_state(state(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gas_sensor_201()->set_counter_pedal(counter_pedal(bytes, length));
  chassis->mutable_acura_ilx()->mutable_gas_sensor_201()->set_checksum_pedal(checksum_pedal(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'interceptor_gas', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gassensor201::interceptor_gas(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'interceptor_gas2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gassensor201::interceptor_gas2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 3);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  int ret = x;
  return ret;
}

// config detail: {'bit': 39, 'enum': {0: 'STATE_NO_FAULT', 1: 'STATE_FAULT_BAD_CHECKSUM', 2: 'STATE_FAULT_SEND', 3: 'STATE_FAULT_SCE', 4: 'STATE_FAULT_STARTUP', 5: 'STATE_FAULT_TIMEOUT'}, 'is_signed_var': False, 'len': 4, 'name': 'state', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Gas_sensor_201::StateType Gassensor201::state(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(4, 4);

  Gas_sensor_201::StateType ret =  static_cast<Gas_sensor_201::StateType>(x);
  return ret;
}

// config detail: {'bit': 35, 'is_signed_var': False, 'len': 4, 'name': 'counter_pedal', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gassensor201::counter_pedal(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 8, 'name': 'checksum_pedal', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Gassensor201::checksum_pedal(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
