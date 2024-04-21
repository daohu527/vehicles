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

class Scmbuttons1a6 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Scmbuttons1a6();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'enum': {0: 'CRUISE_BUTTONS_NONE', 1: 'CRUISE_BUTTONS_MAIN', 2: 'CRUISE_BUTTONS_CANCEL', 3: 'CRUISE_BUTTONS_DECEL_SET', 4: 'CRUISE_BUTTONS_ACCEL_RES', 5: 'CRUISE_BUTTONS_TBD', 6: 'CRUISE_BUTTONS_TBD', 7: 'CRUISE_BUTTONS_TBD'}, 'is_signed_var': False, 'len': 3, 'name': 'CRUISE_BUTTONS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scm_buttons_1a6::Cruise_buttonsType cruise_buttons(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'enum': {0: 'LIGHTS_SETTING_NO_LIGHTS', 1: 'LIGHTS_SETTING_POSITION', 2: 'LIGHTS_SETTING_LOW_BEAM', 3: 'LIGHTS_SETTING_HIGH_BEAM'}, 'is_signed_var': False, 'len': 2, 'name': 'LIGHTS_SETTING', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scm_buttons_1a6::Lights_settingType lights_setting(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 1, 'name': 'MAIN_ON', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool main_on(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 43, 'enum': {0: 'CRUISE_SETTING_NONE', 1: 'CRUISE_SETTING_LKAS_BUTTON', 2: 'CRUISE_SETTING_TBD', 3: 'CRUISE_SETTING_DISTANCE_ADJ'}, 'is_signed_var': False, 'len': 2, 'name': 'CRUISE_SETTING', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Scm_buttons_1a6::Cruise_settingType cruise_setting(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


