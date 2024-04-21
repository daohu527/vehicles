load("//tools:cpplint.bzl", "cpplint")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "acura_ilx_vehicle_factory",
    srcs = [
        "acura_ilx_vehicle_factory.cc",
    ],
    hdrs = [
        "acura_ilx_vehicle_factory.h",
    ],
    deps = [
        ":acura_ilx_controller",
        ":acura_ilx_message_manager",
        "//modules/canbus/vehicle:abstract_vehicle_factory",
    ],
)

cc_library(
    name = "acura_ilx_message_manager",
    srcs = [
        "acura_ilx_message_manager.cc",
    ],
    hdrs = [
        "acura_ilx_message_manager.h",
    ],
    deps = [
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/common_msgs/chassis_msgs:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle/acura_ilx/protocol:canbus_acura_ilx_protocol",
    ],
)

cc_library(
    name = "acura_ilx_controller",
    srcs = [
        "acura_ilx_controller.cc",
    ],
    hdrs = [
        "acura_ilx_controller.h",
    ],
    deps = [
        ":acura_ilx_message_manager",
        "//modules/drivers/canbus/can_comm:can_sender",
        "//modules/drivers/canbus/common:canbus_common",
        "//modules/common_msgs/chassis_msgs:chassis_detail_cc_proto",
        "//modules/drivers/canbus/can_comm:message_manager_base",
        "//modules/canbus/vehicle:vehicle_controller_base",
        "//modules/canbus/vehicle/acura_ilx/protocol:canbus_acura_ilx_protocol",
    ],
)

cpplint()
