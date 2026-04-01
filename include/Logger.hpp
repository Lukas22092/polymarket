#pragma once

#include <string>
#include <iostream>
#include <thread>
#include <queue>
#include <fstream>
#include "EnumTools.hpp"



class Logger {
    private:
    const std::string file_name_;
    std::ofstream stream_;
    std::thread logger_thread_;
    explicit Logger(const std::string &file_name);

    public:
    static Logger& getInstance()
    {
        static Logger instance("../logfile.log");
        return instance;
    }
    std::ofstream& getStream();

    void write(const std::string& msg);

    ~Logger();


};
#define LOG_ENTRY Logger::getInstance().write("[" + std::string(__FUNCTION__) + ":" + std::to_string(__LINE__) + "] ")
#define LOG_THIS(LOG_MODE, log_message) std::cout << "[" << EnumTools::EnumToString(LOG_MODE) << "]"<< " " << log_message << "\n"
