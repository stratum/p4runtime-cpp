load("@rules_cc//cc:defs.bzl", "cc_binary")

cc_binary(
    name = "p4rt_client",
    srcs = ["p4rt_client.cc"],
    deps = [
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_p4lang_p4runtime//:p4info_cc_proto",
        "@com_github_p4lang_p4runtime//:p4runtime_cc_grpc",
        "@com_github_stratum_p4runtime_cpp//p4runtime_cpp:entity_management",
        "@com_github_stratum_p4runtime_cpp//p4runtime_cpp:p4runtime_session",
        "@com_google_absl//absl/flags:flag",
        "@com_google_absl//absl/flags:parse",
        "@com_google_absl//absl/flags:usage",
        "@com_google_protobuf//:protobuf",
    ],
)
