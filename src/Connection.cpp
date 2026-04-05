//wss://stream.binance.com:9443/ws/btcusdt@trade
//wss://echo.websocket.org
#include "Connection.hpp"
#include "Logger.hpp"
#include "parsing.hpp"

Connection::Connection(
    std::shared_ptr<net::io_context> ioc_,
    const bool has_subscription)
    : 
    ioc_(ioc_),
    has_subscription_(has_subscription),
    ctx_({ssl::context::tlsv12_client}),
    resolver_{*ioc_}, 
    ws_{*ioc_, ctx_},
    m_{},
    cv_{}
    {
        /*set in constructor for RAII*/
        //ordering of members should not leak if a exception in thrown
        ctx_.set_verify_mode(ssl::verify_peer);
        ctx_.set_default_verify_paths();
    }

auto Connection::connect(std::string& host, const char* port) -> void
{
    LOG_ENTRY;
    auto new_host = host.substr(host.find_last_of('/') + 1);


    const auto& results = resolver_.resolve(new_host, port);
    const auto& ep = net::connect(beast::get_lowest_layer(ws_), results);
    if(!SSL_set_tlsext_host_name(ws_.next_layer().native_handle(), new_host.c_str()))
    {
        throw beast::system_error(
            static_cast<int>(::ERR_get_error()),
            net::error::get_ssl_category());
    }
    ws_.next_layer().set_verify_callback(ssl::host_name_verification(new_host));
    new_host += ':' + std::to_string(ep.port());

        ws_.set_option(websocket::stream_base::decorator(
            [](websocket::request_type& req)
            {
                req.set(http::field::user_agent,
                    std::string(BOOST_BEAST_VERSION_STRING) +
                        " websocket-client-coro");
            }));
    ws_.next_layer().handshake(ssl::stream_base::client);
    ws_.handshake(new_host, "/ws/btcusdt@trade");
    
    }

auto Connection::receive() -> void
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(m_);
        LOG_ENTRY;
        ws_.read(buffer_);
        cv_.notify_one();
    }
}; 


[[nodiscard]] auto Connection::get_item() -> boost::json::value 
{
    std::unique_lock<std::mutex> lock(m_);
    cv_.wait(lock, [this]{ return !(buffer_.size() == 0);});
    std::string_view sv{static_cast<char const*>(buffer_.data().data()), buffer_.size()};
    LOG_ENTRY;

    auto jv = Parser::parse(sv);
    
    buffer_.consume(buffer_.size());
    
    return jv;
}


Connection::~Connection()
{
        LOG_ENTRY;
        beast::error_code ec;
        ws_.close(websocket::close_code::normal, ec);
        
        if(ec)
            LOG_THIS(LogLevel::Warn) << "Error during closing connection :" << ec.what() << std::endl;
}

