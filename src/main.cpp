#include "Connection.hpp"

auto main() -> int
{
    auto ctx = std::make_shared<boost::asio::io_context>();
    Connection foo("ws://...", ctx, false);

    
    std::print("Hello world");
}