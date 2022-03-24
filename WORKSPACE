load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/9f5b2c782ad50df4692bc66f1687e1f4d43c7308.zip"],
  strip_prefix = "abseil-cpp-9f5b2c782ad50df4692bc66f1687e1f4d43c7308",
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