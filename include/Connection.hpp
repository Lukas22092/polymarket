#include <boost/beast/core.hpp>
#include <boost/beast/websocket.hpp>
#include <boost/beast/websocket/ssl.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl.hpp>
#include <print>
#include <iostream>
#include <memory>
namespace beast = boost::beast;         // from <boost/beast.hpp>
namespace http = beast::http;           // from <boost/beast/http.hpp>
namespace websocket = beast::websocket; // from <boost/beast/websocket.hpp>
namespace net = boost::asio;            // from <boost/asio.hpp>
namespace ssl = boost::asio::ssl;       // from <boost/asio/ssl.hpp>
using tcp = boost::asio::ip::tcp;       // from <boost/asio/ip/tcp.hpp>

class Connection
{
    private:
    const std::string url_;
    std::shared_ptr<net::io_context> ioc_;    
    bool has_subscription_;
    ssl::context ctx_; //
    tcp::resolver resolver_;
    websocket::stream<ssl::stream<tcp::socket>> ws_;
    beast::flat_buffer buffer_;


    public:
    explicit Connection(const std::string& url, std::shared_ptr<net::io_context> ioc_, const bool has_subscription);
    auto connect(std::string& host, const char* port) -> void;
    auto receive() -> void;



    ~Connection();

};