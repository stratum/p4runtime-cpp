// Copyright 2021-present Open Networking Foundation
// SPDX-License-Identifier: Apache-2.0

#include <iostream>
#include <memory>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "absl/flags/usage.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/security/credentials.h"
#include "p4/v1/p4runtime.pb.h"
#include "p4runtime_cpp/entity_management.h"
#include "p4runtime_cpp/p4runtime_session.h"

ABSL_FLAG(std::string, grpc_addr, "127.0.0.1:9339",
          "P4Runtime server address.");
ABSL_FLAG(uint64_t, device_id, 1, "P4Runtime device ID.");

namespace p4runtime_cpp_example {

absl::Status Main(int argc, char** argv) {
  // Start a new client session.
  auto status_or_session = p4runtime_cpp::P4RuntimeSession::Create(
      absl::GetFlag(FLAGS_grpc_addr), ::grpc::InsecureChannelCredentials(),
      absl::GetFlag(FLAGS_device_id));
  if (!status_or_session.ok()) {
    return status_or_session.status();
  }
  // Unwrap the session from the StatusOr object.
  std::unique_ptr<p4runtime_cpp::P4RuntimeSession> session =
      std::move(status_or_session).value();
  // Fetch the current pipeline config from the switch.
  ::p4::config::v1::P4Info p4_info;
  std::string p4_device_config;
  ::absl::Status result =
      GetForwardingPipelineConfig(session.get(), &p4_info, &p4_device_config);
  if (!result.ok()) {
    return result;
  }

  return absl::OkStatus();
}

}  // namespace p4runtime_cpp_example

int main(int argc, char** argv) {
  // Basic Abseil flags and usage setup.
  absl::SetProgramUsageMessage(
      "This program demonstrates basic use of the P4RuntimeSession library.");
  absl::ParseCommandLine(argc, argv);

  // Run the Main function and log errors.
  absl::Status status = p4runtime_cpp_example::Main(argc, argv);
  if (!status.ok()) {
    std::cerr << status << std::endl;
  } else {
    std::cout << "All done." << std::endl;
  }

  // Pass the error code to the shell.
  return status.raw_code();
}
