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

class Wheelspeeds1d0 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Wheelspeeds1d0();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 15, 'name': 'WHEEL_SPEED_FL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double wheel_speed_fl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 15, 'name': 'WHEEL_SPEED_FR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double wheel_speed_fr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 25, 'is_signed_var': False, 'len': 15, 'name': 'WHEEL_SPEED_RL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double wheel_speed_rl(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'is_signed_var': False, 'len': 15, 'name': 'WHEEL_SPEED_RR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double wheel_speed_rr(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


