#include <iostream>
#include <functional>
#include <array>
#include <cstdlib> // for malloc() and free()
#include <gtest/gtest.h>
using namespace std;

// replace operator new and delete to log allocations
void* operator new(std::size_t n) {
	cout << "Allocating " << n << " bytes" << endl;
	return malloc(n);
}
void operator delete(void* p) throw() {
	free(p);
}

TEST(Lambda, basic) {
    std::array<char, 16> arr1{};
    #pragma clang diagnostic ignored "-Wunused-lambda-capture"
    auto lambda1 = [arr1](){}; 
    cout << "Assigning lambda1 of size " << sizeof(lambda1) << endl;
    std::function<void()> f1 = lambda1;

    std::array<char, 25> arr2{};
    #pragma clang diagnostic ignored "-Wunused-lambda-capture"
    auto lambda2 = [arr2](){}; 
    cout << "Assigning lambda2 of size " << sizeof(lambda2) << endl;
    std::function<void()> f2 = lambda2;
}