#include <stdio.h>
#include <gtest/gtest.h>

TEST(pointer, basic) {
  char data[] = "hello";
  char* c = data;
  c[1] = '2';
  EXPECT_EQ(c, data);

  const char *p = data;
  EXPECT_EQ(p, data);
  // 指向是的只读区域不能修改
  // error: read-only variable is not assignable
  // p[2] = '3';

  char* const d = data;
  EXPECT_EQ(d, data);
  d[2] = '3';
  char another_data[] = "world";
  // cannot assign to variable 'd' with const-qualified type 'char *const'
  // d  = another_data;

  // 顶层const 和底层const 
  /*  
    顶层const表示对象本身(指针本身也是一个对象)是常量、底层const一般用于指针，表示指向的对象是常量无法修改
    只有指针才有所谓的顶层const和底层const，一般的对象只有顶层const
    区分顶层const和底层const的方法就是看const是在指针左边，还是右边，在左边就是顶层const，在右边就是底层const

    int * const p1        顶层const，表示p1对象本身是常量，无法修改
    const int p2          不是指针，没有所谓的底层const一说，都是顶层const
    int const p3          和上面的没有区别
    const int * p4        底层const表示指向的对象是常量，无法修改
    const int * const p5  底层+顶层 const

    引用都是底层const

    口诀: 右顶、左底
  */
}