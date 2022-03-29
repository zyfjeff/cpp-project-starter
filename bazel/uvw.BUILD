cc_library(
    name = "uvw",
    hdrs = glob(
        ["src/**"],
        exclude = ["src/CMakeLists.txt"]
    ),
    includes = [
        "src",
    ],
    visibility = ["//visibility:public"],
    deps = ["@com_github_libuv//:libuv"],
)