#include <iostream>
#include <asio.hpp>
#include <gtest/gtest.h>

TEST(AsioTest, Basic) {
    asio::io_context io;
    asio::steady_timer t(io, asio::chrono::seconds(5));
    t.wait();
    std::cout << "Hello, world!" << std::endl;
}
