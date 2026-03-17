#include "Logger.hpp"

Logger::Logger(const std::string &file_name, std::queue<std::string> queue_)
: file_name_(file_name), queue_(std::move(queue_)){}

void Logger::log(std::string&& data)
{
    this->queue_.push(data);
}
void Logger::write()
{
    //use seperate thread and do open and close in con and destructors for RAII
    this->stream.open("log");
    this->stream << "writing logging data\n";
    this->stream.close();
}
