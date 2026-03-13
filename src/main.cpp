#include <iostream>
#include <boost/asio.hpp>
#include "Logger.hpp"

int main()
{
    std::queue<std::string> q;
    Logger logger("log", q);

    logger.log("GHello");
    logger.log("Foooo");
    logger.write();
}