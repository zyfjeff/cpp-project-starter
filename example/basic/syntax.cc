#include <string>
#include <vector>

#include <gtest/gtest.h>

struct Foo {
  uint8_t tiny;
  uint32_t normal;
  uint8_t small;
  uint64_t ln;
  uint16_t sh;
};

TEST(LayoutTest, c_layout) { EXPECT_EQ(sizeof(Foo), 32); }