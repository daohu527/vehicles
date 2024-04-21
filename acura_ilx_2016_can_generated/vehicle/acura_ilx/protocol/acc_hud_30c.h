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

class Acchud30c : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Acchud30c();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'description': 'Used by Nidec', 'is_signed_var': False, 'len': 16, 'name': 'PCM_SPEED', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|250]', 'physical_unit': 'kph', 'precision': 0.01, 'type': 'double'}
  double pcm_speed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 23, 'description': 'Used by Nidec', 'is_signed_var': False, 'len': 8, 'name': 'PCM_GAS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|127]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int pcm_gas(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 31, 'description': '255 = no speed', 'enum': {252: 'CRUISE_SPEED_STOPPED', 255: 'CRUISE_SPEED_NO_SPEED'}, 'is_signed_var': False, 'len': 8, 'name': 'CRUISE_SPEED', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': 'kph', 'precision': 1.0, 'type': 'enum'}
  Acc_hud_30c::Cruise_speedType cruise_speed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 39, 'is_signed_var': False, 'len': 1, 'name': 'DTC_MODE', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool dtc_mode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 38, 'is_signed_var': False, 'len': 1, 'name': 'BOH', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool boh(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 37, 'is_signed_var': False, 'len': 1, 'name': 'ACC_PROBLEM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool acc_problem(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 35, 'is_signed_var': False, 'len': 1, 'name': 'FCM_OFF', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool fcm_off(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 36, 'is_signed_var': False, 'len': 1, 'name': 'FCM_OFF_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool fcm_off_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 34, 'is_signed_var': False, 'len': 1, 'name': 'FCM_PROBLEM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool fcm_problem(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 33, 'is_signed_var': False, 'len': 1, 'name': 'RADAR_OBSTRUCTED', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool radar_obstructed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 1, 'name': 'ENABLE_MINI_CAR', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool enable_mini_car(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 47, 'is_signed_var': False, 'len': 2, 'name': 'HUD_DISTANCE', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int hud_distance(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 45, 'enum': {0: 'HUD_LEAD_NO_CAR', 1: 'HUD_LEAD_DASHED_CAR', 2: 'HUD_LEAD_SOLID_CAR', 3: 'HUD_LEAD_NO_CAR'}, 'is_signed_var': False, 'len': 2, 'name': 'HUD_LEAD', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'enum'}
  Acc_hud_30c::Hud_leadType hud_lead(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 43, 'is_signed_var': False, 'len': 1, 'name': 'BOH_3', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool boh_3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'is_signed_var': False, 'len': 1, 'name': 'BOH_4', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool boh_4(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 41, 'is_signed_var': False, 'len': 1, 'name': 'BOH_5', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool boh_5(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 1, 'name': 'CRUISE_CONTROL_LABEL', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool cruise_control_label(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 55, 'is_signed_var': False, 'len': 1, 'name': 'SET_ME_X01_2', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool set_me_x01_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 54, 'is_signed_var': False, 'len': 1, 'name': 'IMPERIAL_UNIT', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool imperial_unit(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 52, 'is_signed_var': False, 'len': 1, 'name': 'ACC_ON', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool acc_on(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 51, 'is_signed_var': False, 'len': 3, 'name': 'CHIME', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int chime(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 48, 'is_signed_var': False, 'len': 1, 'name': 'SET_ME_X01', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool set_me_x01(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 63, 'is_signed_var': False, 'len': 2, 'name': 'ICONS', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int icons(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 61, 'is_signed_var': False, 'len': 2, 'name': 'COUNTER', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int counter(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 59, 'is_signed_var': False, 'len': 4, 'name': 'CHECKSUM', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int checksum(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo


