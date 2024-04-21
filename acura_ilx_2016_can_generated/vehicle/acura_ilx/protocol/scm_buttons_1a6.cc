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

#include "modules/canbus/vehicle/acura_ilx/protocol/scm_buttons_1a6.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Scmbuttons1a6::Scmbuttons1a6() {}
const int32_t Scmbuttons1a6::ID = 0x1A6;

void Scmbuttons1a6::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_cruise_buttons(cruise_buttons(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_lights_setting(lights_setting(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_main_on(main_on(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_cruise_setting(cruise_setting(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_buttons_1a6()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 7, 'enum': {0: 'CRUISE_BUTTONS_NONE', 1: 'CRUISE_BUTTONS_MAIN', 2: 'CRUISE_BUTTONS_CANCEL', 3: 'CRUISE_BUTTONS_DECEL_SET', 4: 'CRUISE_BUTTONS_ACCEL_RES', 5: 'CRUISE_BUTTONS_TBD', 6: 'CRUISE_BUTTONS_TBD', 7: 'CRUISE_BUTTONS_TBD'}, 'is_signed_var': False, 'len': 3, 'name': 'cruise_buttons', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|7]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scm_buttons_1a6::Cruise_buttonsType Scmbuttons1a6::cruise_buttons(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 3);

  Scm_buttons_1a6::Cruise_buttonsType ret =  static_cast<Scm_buttons_1a6::Cruise_buttonsType>(x);
  return ret;
}

// config detail: {'bit': 1, 'enum': {0: 'LIGHTS_SETTING_NO_LIGHTS', 1: 'LIGHTS_SETTING_POSITION', 2: 'LIGHTS_SETTING_LOW_BEAM', 3: 'LIGHTS_SETTING_HIGH_BEAM'}, 'is_signed_var': False, 'len': 2, 'name': 'lights_setting', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scm_buttons_1a6::Lights_settingType Scmbuttons1a6::lights_setting(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 2);

  Scm_buttons_1a6::Lights_settingType ret =  static_cast<Scm_buttons_1a6::Lights_settingType>(x);
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 1, 'name': 'main_on', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Scmbuttons1a6::main_on(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 43, 'enum': {0: 'CRUISE_SETTING_NONE', 1: 'CRUISE_SETTING_LKAS_BUTTON', 2: 'CRUISE_SETTING_TBD', 3: 'CRUISE_SETTING_DISTANCE_ADJ'}, 'is_signed_var': False, 'len': 2, 'name': 'cruise_setting', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Scm_buttons_1a6::Cruise_settingType Scmbuttons1a6::cruise_setting(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 2);

  Scm_buttons_1a6::Cruise_settingType ret =  static_cast<Scm_buttons_1a6::Cruise_settingType>(x);
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Scmbuttons1a6::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Scmbuttons1a6::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
