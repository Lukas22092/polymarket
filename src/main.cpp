#include "Connection.hpp"
#include <thread>

auto main() -> int {
    auto ctx = std::make_shared<boost::asio::io_context>();
    Connection conn(ctx, false);
    std::string url = "stream.binance.com";
    
    conn.connect(url, "9443"); 
    
    std::thread worker([&conn]() {
        conn.receive(); 
    });

    std::thread consumer([&conn]() {
        auto foo = conn.get_item(); 
        if(!foo.is_null()) {
            int64_t trade_id = foo.at("t").as_int64();
            std::cout << "timestamp: " << trade_id << "\n";
    }
    });


    

        

    return 0;
}