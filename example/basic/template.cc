#include <iostream>
#include "example/common/type_name.h"
#include <gtest/gtest.h>

template<typename T>
void f(T param){
    std::cout << "param:" << type_name<decltype(param)>()<< std::endl;
}

template<typename T>
void g(std::initializer_list<T> initList){
    T t = 0;
    std::cout << "inner type:" << type_name<decltype(t)>()<< std::endl;
    std::cout << "initList:" << type_name<decltype(initList)>()<< std::endl;
}

TEST(Template, basic) {
    auto x = {11,23,9};
    f(x);
    std::cout << "----------------" << std::endl;
    g(x);
}


TEST(Template, lambda) {
    std::vector<int> v;
    auto resetV = [](auto newValue) { };
    resetV(5);
}

TEST(Template, lambda2) {
    std::vector<int> v1{4, 1};
    std::vector<int> v2(4, 1);
    std::cout << v2.size() << std::endl;
}
