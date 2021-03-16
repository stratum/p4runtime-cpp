// Copyright 2020 Google LLC
// Copyright 2021-present Open Networking Foundation
// SPDX-License-Identifier: Apache-2.0

#include "p4runtime_cpp/entity_management.h"

#include "absl/strings/str_format.h"
#include "absl/strings/str_replace.h"
#include "gtl/map_util.h"
#include "gutil/proto.h"

namespace p4runtime_cpp {

using ::p4::config::v1::P4Info;

absl::Status BuildP4RTEntityIdReplacementMap(
    const P4Info& p4_info,
    absl::flat_hash_map<std::string, std::string>* replacements) {
  RET_CHECK(replacements);

  for (const auto& table : p4_info.tables()) {
    RET_CHECK(gtl::InsertIfNotPresent(
        replacements, absl::StrFormat("{%s}", table.preamble().name()),
        absl::StrFormat("%u", table.preamble().id())));

    // Add match fields as FQ name to lookup table.
    for (const auto& match : table.match_fields()) {
      std::string fqn =
          absl::StrFormat("{%s.%s}", table.preamble().name(), match.name());
      RET_CHECK(gtl::InsertIfNotPresent(replacements, fqn,
                                        absl::StrFormat("%u", match.id())));
    }
  }

  for (const auto& reg : p4_info.registers()) {
    RET_CHECK(gtl::InsertIfNotPresent(
        replacements, absl::StrFormat("{%s}", reg.preamble().name()),
        absl::StrFormat("%u", reg.preamble().id())));
  }

  for (const auto& action : p4_info.actions()) {
    RET_CHECK(gtl::InsertIfNotPresent(
        replacements, absl::StrFormat("{%s}", action.preamble().name()),
        absl::StrFormat("%u", action.preamble().id())));

    // Add action parameters as FQ name to lookup table.
    for (const auto& param : action.params()) {
      std::string fqn =
          absl::StrFormat("{%s.%s}", action.preamble().name(), param.name());
      RET_CHECK(gtl::InsertIfNotPresent(replacements, fqn,
                                        absl::StrFormat("%u", param.id())));
    }
  }

  return absl::OkStatus();
}

absl::Status HydrateP4RuntimeProtoFromString(
    const absl::flat_hash_map<std::string, std::string>& replacements,
    std::string proto_string, ::google::protobuf::Message* message) {
  absl::StrReplaceAll(replacements, &proto_string);
  RETURN_IF_ERROR(gutil::ReadProtoFromString(proto_string, message));

  return absl::OkStatus();
}

absl::Status HydrateP4RuntimeProtoFromString(
    const P4Info& p4_info, std::string proto_string,
    ::google::protobuf::Message* message) {
  absl::flat_hash_map<std::string, std::string> replacements;
  RETURN_IF_ERROR(BuildP4RTEntityIdReplacementMap(p4_info, &replacements));
  return HydrateP4RuntimeProtoFromString(replacements, proto_string, message);
}

}  // namespace p4runtime_cpp
