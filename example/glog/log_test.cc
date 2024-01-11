#include <glog/logging.h>
#include <gtest/gtest.h>

TEST(LogTest, BasicLog) {
     LOG(INFO) << "Hello, world!";
}