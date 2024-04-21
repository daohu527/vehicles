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

#include "modules/canbus/vehicle/acura_ilx/protocol/stalk_status_374.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Stalkstatus374::Stalkstatus374() {}
const int32_t Stalkstatus374::ID = 0x374;

void Stalkstatus374::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_dashboard_alert(dashboard_alert(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_auto_headlights(auto_headlights(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_high_beam_hold(high_beam_hold(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_high_beam_flash(high_beam_flash(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_headlights_on(headlights_on(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_wiper_switch(wiper_switch(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_counter(counter(bytes, length));
  chassis->mutable_acura_ilx()->mutable_stalk_status_374()->set_checksum(checksum(bytes, length));
}

// config detail: {'bit': 39, 'enum': {0: 'DASHBOARD_ALERT_NONE', 51: 'DASHBOARD_ALERT_ACC_PROBLEM', 55: 'DASHBOARD_ALERT_CMBS_PROBLEM', 75: 'DASHBOARD_ALERT_KEY_NOT_DETECTED', 79: 'DASHBOARD_ALERT_FASTEN_SEATBELT', 111: 'DASHBOARD_ALERT_LKAS_PROBLEM', 131: 'DASHBOARD_ALERT_BRAKE_SYSTEM_PROBLEM', 132: 'DASHBOARD_ALERT_BRAKE_HOLD_PROBLEM', 139: 'DASHBOARD_ALERT_TBD', 161: 'DASHBOARD_ALERT_DOOR_OPEN'}, 'is_signed_var': False, 'len': 8, 'name': 'dashboard_alert', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
Stalk_status_374::Dashboard_alertType Stalkstatus374::dashboard_alert(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  Stalk_status_374::Dashboard_alertType ret =  static_cast<Stalk_status_374::Dashboard_alertType>(x);
  return ret;
}

// config detail: {'bit': 46, 'is_signed_var': False, 'len': 1, 'name': 'auto_headlights', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus374::auto_headlights(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 47, 'is_signed_var': False, 'len': 1, 'name': 'high_beam_hold', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus374::high_beam_hold(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 45, 'is_signed_var': False, 'len': 1, 'name': 'high_beam_flash', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus374::high_beam_flash(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 54, 'is_signed_var': False, 'len': 1, 'name': 'headlights_on', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Stalkstatus374::headlights_on(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 53, 'is_signed_var': False, 'len': 2, 'name': 'wiper_switch', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Stalkstatus374::wiper_switch(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'counter', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Stalkstatus374::counter(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(4, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Stalkstatus374::checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
