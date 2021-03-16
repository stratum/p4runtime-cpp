# Copyright 2021-present Open Networking Foundation
# SPDX-License-Identifier: Apache-2.0

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

def p4runtime_cpp_deps():
    http_archive(
        name = "com_google_absl_oss_federation",
        sha256 = "3789365088930757771696bed4f245befeadda9c4496106a6252c5db572ef2e8",
        strip_prefix = "federation-head-2021-03-12-daily",
        urls = ["https://github.com/abseil/federation-head/archive/2021-03-12-daily.zip"],  # 2019-08-05T19:51:58Z
    )

    if "com_github_grpc_grpc" not in native.existing_rules():
        http_archive(
            name = "com_github_grpc_grpc",
            sha256 = "51403542b19e9ed5d3b6551ce4a828e17883a1593d4ca408b098f04b0767d202",
            strip_prefix = "grpc-1.36.2",
            urls = [
                "https://github.com/grpc/grpc/archive/v1.36.2.tar.gz",
            ],
        )

    if "com_github_p4lang_p4runtime" not in native.existing_rules():
        http_archive(
            name = "com_github_p4lang_p4runtime",
            urls = ["https://github.com/p4lang/p4runtime/archive/v1.3.0.zip"],
            strip_prefix = "p4runtime-1.3.0/proto",
            sha256 = "20b187a965fab78df9b8253da14166b8666938a82a2aeea16c6f9abaa934bdcb",
        )

    if not native.existing_rule("com_github_google_glog"):
        http_archive(
            name = "com_github_google_glog",
            url = "https://github.com/google/glog/archive/v0.4.0.tar.gz",
            strip_prefix = "glog-0.4.0",
            sha256 = "f28359aeba12f30d73d9e4711ef356dc842886968112162bc73002645139c39c",
        )

    if not native.existing_rule("com_github_gflags_gflags"):
        http_archive(
            name = "com_github_gflags_gflags",
            url = "https://github.com/gflags/gflags/archive/v2.2.2.tar.gz",
            strip_prefix = "gflags-2.2.2",
            sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
        )

    if not native.existing_rule("com_github_bazelbuild_buildtools"):
        http_archive(
            name = "com_github_bazelbuild_buildtools",
            sha256 = "a02ba93b96a8151b5d8d3466580f6c1f7e77212c4eb181cba53eb2cae7752a23",
            strip_prefix = "buildtools-3.5.0",
            url = "https://github.com/bazelbuild/buildtools/archive/3.5.0.tar.gz",
        )
