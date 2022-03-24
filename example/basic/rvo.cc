#include <string>
#include <vector>
#include <iostream>

#include <gtest/gtest.h>

class BigObject {
 public:
  BigObject() { std::cout << "constructor. " << std::endl; }
  ~BigObject() { std::cout << "destructor." << std::endl; }
  BigObject(const BigObject&) { std::cout << "copy constructor." << std::endl; }
  BigObject(BigObject&&) { std::cout << "move constructor" << std::endl; }
};

BigObject foo(int n) {
  BigObject localObj;
#pragma clang diagnostic ignored "-Wpessimizing-move"
  // warning: moving a local object in a return statement prevents copy elision [-Wpessimizing-move]
  return std::move(localObj); // remove std::move call here
}

BigObject foo2(int n) { return BigObject(); }

BigObject foo3(int n) {
  BigObject localObj;
  return localObj;
}

BigObject foo4(int n) {
  BigObject localObj1;
  BigObject localObj2;
  bool cond = false;
  if (cond) {
    return localObj1;
  } else {
    return localObj2;
  }
}

TEST(Opt, RVO) {
  /*
      constructor.
      move constructor
      destructor.
      destructor.
  */
  //auto f = foo(1);

  /*
      constructor.
      destructor.
  */
  //auto f2 = foo2(1);

  /*
      constructor.
      destructor.
  */
  //auto f3 = foo3(1);

  // RVO失效
  /*
   constructor.
   constructor.
   move constructor
   destructor.
   destructor.
   destructor.
  */
  //auto f4 = foo4(1);

  /*
   bazel test -c opt --cxxopt="-fno-elide-constructors" //example/basic:rvo --test_output=all 
   // 禁用RVO
   constructor.
   move constructor
   destructor.
   destructor.
  */
  auto f3 = foo3(1);
}