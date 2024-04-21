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

class Stalkstatus374 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Stalkstatus374();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 39, 'enum': {0: 'DASHBOARD_ALERT_NONE', 51: 'DASHBOARD_ALERT_ACC_PROBLEM', 55: 'DASHBOARD_ALERT_CMBS_PROBLEM', 75: 'DASHBOARD_ALERT_KEY_NOT_DETECTED', 79: 'DASHBOARD_ALERT_FASTEN_SEATBELT', 111: 'DASHBOARD_ALERT_LKAS_PROBLEM', 131: 'DASHBOARD_ALERT_BRAKE_SYSTEM_PROBLEM', 132: 'DASHBOARD_ALERT_BRAKE_HOLD_PROBLEM', 139: 'DASHBOARD_ALERT_TBD', 161: 'DASHBOARD_ALERT_DOOR_OPEN'}, 'is_signed_var': False, 'len': 8, 'name': 'DASHBOARD_ALERT', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Stalk_status_374::Dashboard_alertType dashboard_alert(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 46, 'is_signed_var': False, 'len': 1, 'name': 'AUTO_HEADLIGHTS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool auto_headlights(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 1, 'name': 'HIGH_BEAM_HOLD', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool high_beam_hold(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 45, 'is_signed_var': False, 'len': 1, 'name': 'HIGH_BEAM_FLASH', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool high_beam_flash(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 54, 'is_signed_var': False, 'len': 1, 'name': 'HEADLIGHTS_ON', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool headlights_on(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 53, 'is_signed_var': False, 'len': 2, 'name': 'WIPER_SWITCH', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int wiper_switch(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


