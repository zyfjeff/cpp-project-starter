#include <memory>
#include "uvw.hpp"
#include <gtest/gtest.h>

void listen(uvw::Loop &loop) {
    std::shared_ptr<uvw::TCPHandle> tcp = loop.resource<uvw::TCPHandle>();

    tcp->once<uvw::ListenEvent>([](const uvw::ListenEvent &, uvw::TCPHandle &srv) {
        std::shared_ptr<uvw::TCPHandle> client = srv.loop().resource<uvw::TCPHandle>();

        client->on<uvw::CloseEvent>([ptr = srv.shared_from_this()](const uvw::CloseEvent &, uvw::TCPHandle &) { ptr->close(); });
        client->on<uvw::EndEvent>([](const uvw::EndEvent &, uvw::TCPHandle &client) { client.close(); });

        srv.accept(*client);
        client->read();
    });

    tcp->bind("127.0.0.1", 4242);
    tcp->listen();
}

void conn(uvw::Loop &loop) {
    auto tcp = loop.resource<uvw::TCPHandle>();

    tcp->on<uvw::ErrorEvent>([](const uvw::ErrorEvent &, uvw::TCPHandle &) { /* handle errors */ });

    tcp->once<uvw::ConnectEvent>([](const uvw::ConnectEvent &, uvw::TCPHandle &tcp) {
        auto dataWrite = std::unique_ptr<char[]>(new char[2]{ 'b', 'c' });
        tcp.write(std::move(dataWrite), 2);
        tcp.close();
    });

    tcp->connect(std::string{"127.0.0.1"}, 4242);
}

TEST(uvw, basic) {
  auto loop = uvw::Loop::getDefault();
  listen(*loop);
  conn(*loop);
  loop->run();
}

TEST(uvw, asan_error) {
  auto loop = uvw::Loop::create();
  auto timer = loop->resource<uvw::TimerHandle>();
  timer->on<uvw::TimerEvent>([](uvw::TimerEvent&, uvw::TimerHandle&) {});
  timer->start(uvw::TimerHandle::Time(0), uvw::TimerHandle::Time(1000));
  timer->close();
  loop->close();
}