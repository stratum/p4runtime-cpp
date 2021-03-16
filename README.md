# P4Runtime C++ Reference Library

This repository contains the C++ reference library for
[P4Runtime](https://github.com/p4lang/p4runtime). It provides convenient
interfaces and helper functions to implement both P4RT clients and servers.

The eventual goal is to move it under the [p4lang](https://github.com/p4lang)
organization.

## Quickstart (Bazel)

Add these lines to your WORKSPACE file:

```python
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_stratum_p4runtime_cpp",
    urls = ["https://github.com/stratum/p4runtime-cpp/archive/main.zip"],
    sha256 = "<checksum>",
    strip_prefix = "p4runtime-cpp-main",
)

# Load (transitive) dependencies.
load("@com_github_stratum_p4runtime_cpp//bazel:deps.bzl", "p4runtime_cpp_deps")

p4runtime_cpp_deps()

load("@com_google_absl_oss_federation//:federation_deps.bzl", "federation_deps")

federation_deps()

load("@com_github_p4lang_p4runtime//:p4runtime_deps.bzl", "p4runtime_deps")

p4runtime_deps()

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

load("@com_google_googleapis//:repository_rules.bzl", "switched_rules_by_language")

switched_rules_by_language(
    name = "com_google_googleapis_imports",
    cc = True,
    grpc = True,
    python = True,
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()
```

## Usage Examples

See: [examples](examples).

## Docs

TODO
