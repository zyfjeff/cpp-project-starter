load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "com_google_absl",
    remote = "https://github.com/abseil/abseil-cpp.git",
    tag = "20230125.3",
)

http_archive(
  name = "com_google_tcmalloc",
  urls = ["https://github.com/google/tcmalloc/archive/ce51e47bbb707990cb77895b80dd0c4691f8916b.zip"],
  strip_prefix = "tcmalloc-ce51e47bbb707990cb77895b80dd0c4691f8916b",
)

git_repository(
  name = "com_google_googletest",
  remote = "https://github.com/google/googletest.git",
  tag = "v1.14.0"
)

http_archive(
    name = "com_github_gflags_gflags",
    sha256 = "34af2f15cf7367513b352bdcd2493ab14ce43692d2dcd9dfc499492966c64dcf",
    strip_prefix = "gflags-2.2.2",
    urls = ["https://github.com/gflags/gflags/archive/v2.2.2.tar.gz"],
)

http_archive(
    name = "com_github_google_glog",
    sha256 = "122fb6b712808ef43fbf80f75c52a21c9760683dae470154f02bddfc61135022",
    strip_prefix = "glog-0.6.0",
    urls = ["https://github.com/google/glog/archive/v0.6.0.zip"],
)

git_repository(
  name = "com_google_benchmark",
  remote = "https://github.com/google/benchmark.git",
  tag = "v1.7.1"
)

git_repository(
    name = "rules_proto_grpc",
    remote = "https://github.com/rules-proto-grpc/rules_proto_grpc.git",
    tag = "4.3.0"
)

# Rule repository, note that it's recommended to use a pinned commit to a released version of the rules
http_archive(
   name = "rules_foreign_cc",
   sha256 = "30c970bfaeda3485100c62b13093da2be2c70ed99ec8d30f4fac6dd37cb25f34",
   strip_prefix = "rules_foreign_cc-0.6.0",
   url = "https://github.com/bazelbuild/rules_foreign_cc/archive/0.6.0.zip",
)

http_archive(
  name = "hedron_compile_commands",
  url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/dc36e462a2468bd79843fe5176542883b8ce4abe.tar.gz",
  sha256 = "d63c1573eb1daa4580155a1f0445992878f4aa8c34eb165936b69504a8407662",
  strip_prefix = "bazel-compile-commands-extractor-dc36e462a2468bd79843fe5176542883b8ce4abe",
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

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()