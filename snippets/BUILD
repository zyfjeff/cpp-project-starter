cc_library(
    name = "kfifo_lib",
    srcs = [
        "kfifo.h",
    ],
)

cc_test(
  name = "kfifo_unittests",
  srcs = ["kfifo_unittests.cc"],
  deps = [
      "@googletest//:gtest_main",
      "//snippets:kfifo_lib",
    ],
)