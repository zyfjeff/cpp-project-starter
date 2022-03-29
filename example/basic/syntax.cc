#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

struct Foo {
  uint8_t tiny;
  uint32_t normal;
  uint8_t small;
  uint64_t ln;
  uint16_t sh;
};

TEST(LayoutTest, c_layout) { EXPECT_EQ(sizeof(Foo), 32); }

TEST(Ref, Dangling) {
  std::vector<std::string> data;
  data.push_back("first");
  const std::string& first = data[0];
  data.push_back("second");
  data.push_back("third");
  data.push_back("fourth");
  data.push_back("fifth");
  data.push_back("sixth");
  // Dangling ref
  // std::cout << first << std::endl;
}

TEST(Syntax, basic) {
  //TODO(tianqian.zyf): Why WTF, output 0.4
  puts("-0.4" + 1);
  //  adding 'int' to a string does not append to the string [-Wstring-plus-int]
  // WTF?
  // 被转换成索引操作了，打印从index 1开始后的字符
  /*
  example/basic/syntax.cc:31:15: note: use array indexing to silence this warning
  puts("-0.4" + 1);
              ^
       &      [  ]
  */
  std::cout << "-0.4" + 1 << std::endl;
  // What? print empty
  std::cout << "-0.4" + 4 << std::endl;
}

TEST(Syntax, Compiler) {

}