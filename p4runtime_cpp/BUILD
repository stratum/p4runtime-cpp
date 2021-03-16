# Copyright 2020 Google LLC
# Copyright 2021-present Open Networking Foundation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

load("@rules_cc//cc:defs.bzl", "cc_library")

package(
    default_visibility = ["//visibility:public"],
    licenses = ["notice"],
)

cc_library(
    name = "entity_management",
    srcs = ["entity_management.cc"],
    hdrs = ["entity_management.h"],
    deps = [
        "//gtl:map_util",
        "//gutil:proto",
        "//gutil:status",
        "@com_github_p4lang_p4runtime//:p4info_cc_proto",
        "@com_google_absl//absl/container:flat_hash_map",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
    ],
)

cc_library(
    name = "p4runtime_session",
    srcs = ["p4runtime_session.cc"],
    hdrs = ["p4runtime_session.h"],
    deps = [
        "//gutil:status",
        "@com_github_google_glog//:glog",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_public_hdrs",
        "@com_github_p4lang_p4runtime//:p4runtime_cc_grpc",
        "@com_github_p4lang_p4runtime//:p4runtime_cc_proto",
        "@com_google_absl//absl/memory",
        "@com_google_absl//absl/numeric:int128",
        "@com_google_absl//absl/status",
        "@com_google_absl//absl/status:statusor",
        "@com_google_absl//absl/time",
    ],
)
