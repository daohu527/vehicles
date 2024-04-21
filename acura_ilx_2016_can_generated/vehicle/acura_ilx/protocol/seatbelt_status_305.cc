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

#include "modules/canbus/vehicle/acura_ilx/protocol/seatbelt_status_305.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Seatbeltstatus305::Seatbeltstatus305() {}
const int32_t Seatbeltstatus305::ID = 0x305;

void Seatbeltstatus305::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_seatbelt_driver_lamp(seatbelt_driver_lamp(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_seatbelt_pass_unlatched(seatbelt_pass_unlatched(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_seatbelt_pass_latched(seatbelt_pass_latched(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_seatbelt_driver_unlatched(seatbelt_driver_unlatched(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_seatbelt_driver_latched(seatbelt_driver_latched(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_pass_airbag_off(pass_airbag_off(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_pass_airbag_on(pass_airbag_on(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_seatbelt_status_305()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'seatbelt_driver_lamp', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::seatbelt_driver_lamp(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'seatbelt_pass_unlatched', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::seatbelt_pass_unlatched(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'seatbelt_pass_latched', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::seatbelt_pass_latched(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'seatbelt_driver_unlatched', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::seatbelt_driver_unlatched(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 13, 'is_signed_var': False, 'len': 1, 'name': 'seatbelt_driver_latched', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::seatbelt_driver_latched(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 14, 'description': 'Might just be indicator light', 'is_signed_var': False, 'len': 1, 'name': 'pass_airbag_off', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::pass_airbag_off(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 15, 'description': 'Might just be indicator light', 'is_signed_var': False, 'len': 1, 'name': 'pass_airbag_on', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Seatbeltstatus305::pass_airbag_on(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 53, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Seatbeltstatus305::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 51, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Seatbeltstatus305::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
