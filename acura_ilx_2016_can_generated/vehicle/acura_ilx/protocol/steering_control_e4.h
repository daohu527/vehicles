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

class Steeringcontrole4 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Steeringcontrole4();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': True, 'len': 16, 'name': 'STEER_TORQUE', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[-3840|3840]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int steer_torque(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'is_signed_var': False, 'len': 1, 'name': 'STEER_TORQUE_REQUEST', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool steer_torque_request(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'is_signed_var': False, 'len': 8, 'name': 'SET_ME_X00', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int set_me_x00(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


