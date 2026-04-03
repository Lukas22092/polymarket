#include "Connection.hpp"
#include "Logger.hpp"


auto main() -> int
{
    LOG_ENTRY;
    std::cout << "starting\n";
    auto ctx = std::make_shared<boost::asio::io_context>();

    
    std::unique_ptr<Connection> connection = std::make_unique<Connection>(ctx, false);
    std::string url = "wss://stream.binance.com";
    
    connection->connect(url, "9443");
   
    
    auto foo = connection->get_item();
    std::cout << "foo\n";

    int a = 23;
    

    return 0;
}