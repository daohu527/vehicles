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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/common_msgs/chassis_msgs/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

class Enginedata158 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Enginedata158();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 16, 'name': 'XMISSION_SPEED', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double xmission_speed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 16, 'name': 'ENGINE_RPM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15000]', 'physical_unit': 'rpm', 'precision': 1.0, 'type': 'int'}
  int engine_rpm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 16, 'name': 'XMISSION_SPEED2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double xmission_speed2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 8, 'name': 'ODOMETER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|2550]', 'physical_unit': 'm', 'precision': 10.0, 'type': 'double'}
  double odometer(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


