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

#include "modules/canbus/vehicle/acura_ilx/protocol/scm_feedback_294.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

using ::apollo::drivers::canbus::Byte;

Scmfeedback294::Scmfeedback294() {}
const int32_t Scmfeedback294::ID = 0x294;

void Scmfeedback294::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_acura_ilx()->mutable_scm_feedback_294()->set_right_blinker(right_blinker(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_feedback_294()->set_left_blinker(left_blinker(bytes, length));
  chassis->mutable_acura_ilx()->mutable_scm_feedback_294()->set_wipers_speed(wipers_speed(bytes, length));
}

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'right_blinker', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Scmfeedback294::right_blinker(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'left_blinker', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Scmfeedback294::left_blinker(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 4, 'is_signed_var': False, 'len': 2, 'name': 'wipers_speed', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Scmfeedback294::wipers_speed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 2);

  int ret = x;
  return ret;
}
}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
