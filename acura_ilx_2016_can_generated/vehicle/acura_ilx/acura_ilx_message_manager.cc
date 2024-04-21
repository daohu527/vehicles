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

#include "modules/canbus/vehicle/acura_ilx/acura_ilx_message_manager.h"



#include "modules/canbus/vehicle/acura_ilx/protocol/acc_hud_30c.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/brake_command_1fa.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/brake_pressure_1e7.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/car_speed_309.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/cruise_324.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/cruise_params_37c.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/doors_status_405.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/engine_data_158.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/gas_command_200.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/gas_pedal_13c.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/gas_pedal_2_130.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/gas_sensor_201.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/gearbox_1a3.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/kinematics_91.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/kinematics_alt_94.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/lkas_hud_33d.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/powertrain_data_17c.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/rough_wheel_speed_255.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/scm_buttons_1a6.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/scm_feedback_294.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/seatbelt_status_305.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/stalk_status_2_37b.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/stalk_status_374.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/standstill_1b0.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/steer_motor_torque_1ab.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/steer_status_18f.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/steering_control_e4.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/steering_sensors_156.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/vehicle_dynamics_1ea.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/vsa_status_1a4.h"
#include "modules/canbus/vehicle/acura_ilx/protocol/wheel_speeds_1d0.h"

namespace apollo {
namespace canbus {
namespace acura_ilx {

Acura_ilxMessageManager::Acura_ilxMessageManager() {
  // Control Messages


  // Report Messages
  AddRecvProtocolData<Acchud30c, true>();
  AddRecvProtocolData<Brakecommand1fa, true>();
  AddRecvProtocolData<Brakepressure1e7, true>();
  AddRecvProtocolData<Carspeed309, true>();
  AddRecvProtocolData<Cruise324, true>();
  AddRecvProtocolData<Cruiseparams37c, true>();
  AddRecvProtocolData<Doorsstatus405, true>();
  AddRecvProtocolData<Enginedata158, true>();
  AddRecvProtocolData<Gascommand200, true>();
  AddRecvProtocolData<Gaspedal13c, true>();
  AddRecvProtocolData<Gaspedal2130, true>();
  AddRecvProtocolData<Gassensor201, true>();
  AddRecvProtocolData<Gearbox1a3, true>();
  AddRecvProtocolData<Kinematics91, true>();
  AddRecvProtocolData<Kinematicsalt94, true>();
  AddRecvProtocolData<Lkashud33d, true>();
  AddRecvProtocolData<Powertraindata17c, true>();
  AddRecvProtocolData<Roughwheelspeed255, true>();
  AddRecvProtocolData<Scmbuttons1a6, true>();
  AddRecvProtocolData<Scmfeedback294, true>();
  AddRecvProtocolData<Seatbeltstatus305, true>();
  AddRecvProtocolData<Stalkstatus237b, true>();
  AddRecvProtocolData<Stalkstatus374, true>();
  AddRecvProtocolData<Standstill1b0, true>();
  AddRecvProtocolData<Steeringcontrole4, true>();
  AddRecvProtocolData<Steeringsensors156, true>();
  AddRecvProtocolData<Steermotortorque1ab, true>();
  AddRecvProtocolData<Steerstatus18f, true>();
  AddRecvProtocolData<Vehicledynamics1ea, true>();
  AddRecvProtocolData<Vsastatus1a4, true>();
  AddRecvProtocolData<Wheelspeeds1d0, true>();
}

Acura_ilxMessageManager::~Acura_ilxMessageManager() {}

}  // namespace acura_ilx
}  // namespace canbus
}  // namespace apollo
