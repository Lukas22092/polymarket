#include "Connection.hpp"

auto main() -> int
{
    auto ctx = std::make_shared<boost::asio::io_context>();

    {
        std::unique_ptr<Connection> connection = std::make_unique<Connection>(ctx, false);

        std::string url = "wss://stream.binance.com";
        
        connection->connect(url, "9443"); 
        
    } 

    return 0;
}