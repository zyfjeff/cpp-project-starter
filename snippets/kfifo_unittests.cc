#include <iostream>
#include "kfifo.h"
#include <gtest/gtest.h>


TEST(Kfifo, basic) {
  Kfifo<int, 2> ok;
  EXPECT_FALSE(IsPowOfTwo(1));
  EXPECT_FALSE(IsPowOfTwo(0));
  EXPECT_FALSE(IsPowOfTwo(3));
  EXPECT_FALSE(IsPowOfTwo(5));
  EXPECT_TRUE(IsPowOfTwo(4));
  EXPECT_TRUE(IsPowOfTwo(8));
  EXPECT_FALSE(IsPowOfTwo(6));
}

TEST(Kfifo, in) {
  Kfifo<int, 1024> fifo;
  int count = 0;
  while(count < 1024) {
    EXPECT_EQ(1, fifo.In(&count, 1));
    count++;
  }
  EXPECT_EQ(0, fifo.Unused());
  EXPECT_EQ(0, fifo.In(&count, 1));

  count = 0;
  int expect_count = 0;
  while(count < 1024) {
    fifo.Out(&expect_count, 1);
    EXPECT_EQ(expect_count, count);
    count++;
  }
  EXPECT_EQ(1024, fifo.Unused());
}