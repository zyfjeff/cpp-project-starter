#include <cstdlib>
#include <cstdio>

#include <gtest/gtest.h>

int fooForInt(int a) {
    return a;
}

double fooForDouble(double a) {
    return a;
}

/*
//如果x的数据类型是整型则使用fooForInt函数，否则使用fooForDouble函数。
#define fooFor(x) __builtin_choose_expr(__builtin_types_compatible_p(__typeof__(x), int), fooForInt(x), fooForDouble(x))

TEST(ChooseExpr, basic) {
    //根据传递进入的参数类型来决定使用哪个具体的函数。
    int a = fooFor(10);
    EXPECT_EQ(a, 10);
    double b = fooFor(10.0);
    EXPECT_DOUBLE_EQ(b, 10.0);
}*/