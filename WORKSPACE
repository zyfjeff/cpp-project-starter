load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_absl",
    remote = "https://github.com/abseil/abseil-cpp.git",
    tag = "20211102.0",
)

http_archive(
  name = "com_google_tcmalloc",
  urls = ["https://github.com/google/tcmalloc/archive/930de23c7e1b218f605530406a7a405496cbfadf.zip"],
  strip_prefix = "tcmalloc-930de23c7e1b218f605530406a7a405496cbfadf",
)

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/b007c54f2944e193ac44fba1bc997cb65826a0b9.zip"],
  strip_prefix = "googletest-b007c54f2944e193ac44fba1bc997cb65826a0b9",
)

http_archive(
  name = "com_google_benchmark",
  urls = ["https://github.com/google/benchmark/archive/a480a088fe647eb829ead0d0bbbd5821b2cc8b85.zip"],
  strip_prefix = "googletest-a480a088fe647eb829ead0d0bbbd5821b2cc8b85",
)

http_archive(
    name = "com_grail_bazel_compdb",
    strip_prefix = "bazel-compilation-database-be2ea876e64d9047ead799281f594d7b924c1c09",
    urls = ["https://github.com/grailbio/bazel-compilation-database/archive/be2ea876e64d9047ead799281f594d7b924c1c09.tar.gz"],
)

http_archive(
    name = "rules_proto_grpc",
    sha256 = "507e38c8d95c7efa4f3b1c0595a8e8f139c885cb41a76cab7e20e4e67ae87731",
    strip_prefix = "rules_proto_grpc-4.1.1",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/4.1.1.tar.gz"],
)

# Rule repository, note that it's recommended to use a pinned commit to a released version of the rules
http_archive(
   name = "rules_foreign_cc",
   sha256 = "30c970bfaeda3485100c62b13093da2be2c70ed99ec8d30f4fac6dd37cb25f34",
   strip_prefix = "rules_foreign_cc-0.6.0",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.6.0.zip",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")
rules_foreign_cc_dependencies()

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_toolchains", "rules_proto_grpc_repos")
rules_proto_grpc_toolchains()
rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")
rules_proto_dependencies()
rules_proto_toolchains()

load("@rules_proto_grpc//cpp:repositories.bzl", rules_proto_grpc_cpp_repos = "cpp_repos")

rules_proto_grpc_cpp_repos()

load("@com_grail_bazel_compdb//:deps.bzl", "bazel_compdb_deps")
bazel_compdb_deps()

http_archive(
    name = "com_github_uvw",
    build_file = "@//bazel:uvw.BUILD",
    strip_prefix = "uvw-2.12.1_libuv_v1.44",
    urls = [
        "https://github.com/skypjack/uvw/archive/refs/tags/v2.12.1_libuv_v1.44.tar.gz",
    ],
    sha256 = "3460842778e91e7d2fae4201e49e4521e9d94fbbf3891ae6c52d3c9fc0673598",
)

http_archive(
    name = "com_github_libuv",
    build_file = "@//bazel:libuv.BUILD",
    strip_prefix = "libuv-1.44.1",
    urls = [
        "https://github.com/libuv/libuv/archive/refs/tags/v1.44.1.tar.gz",
    ],
    sha256 = "e91614e6dc2dd0bfdd140ceace49438882206b7a6fb00b8750914e67a9ed6d6b",
)