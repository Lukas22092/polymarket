#include "Logger.hpp"

Logger::Logger(const std::string &file_name) 
    : 
    file_name_(file_name) 
    {
    stream_.open(file_name_, std::ios::app);
    }

std::ofstream& Logger::getStream(){return stream_;}

Logger::~Logger()
{
    if(stream_)
        { try{stream_.close();} catch(...){}
    }
}

void Logger::write(const std::string& msg)
{
    stream_ << msg;
}

