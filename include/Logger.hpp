#pragma once

#include <chrono>
#include <string>
#include <iostream>
#include <thread>
#include <queue>
#include <fstream>
#include <cstdlib>
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

    


    ~Logger();

};

/*
* not threadsafe yet. will come soon ig. move this to logger cpp....
*/
struct ScopeLogger {
    const char* func_name;
    const std::chrono::time_point<std::chrono::high_resolution_clock> t1;
    static inline int indent_level = 0;
    static int& getIndentLevel() {
            return indent_level;
        }
    ScopeLogger(const char* name) 
    :
    func_name{name},
    t1{std::chrono::high_resolution_clock::now()}
    {
        indent_level++;
        Logger::getInstance().getStream() 
            << std::string(indent_level * 2, ' ') << ">>" << "[" << EnumToString(LogLevel::Trace) << "] " << func_name << "\n";
    }

    ~ScopeLogger() 
    {
        const auto& t2 = std::chrono::high_resolution_clock::now();
        const auto& duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1);
        Logger::getInstance().getStream() 
           << std::string(indent_level * 2, ' ') << "<<" "[" << EnumToString(LogLevel::Trace) << "]" << "[" << duration << "] " << "~" << func_name <<  "\n";
        indent_level--;

    }
};

#define LOG_ENTRY ScopeLogger _scope_logger(__FUNCTION__)
#define LOG_THIS(LogLevel) Logger::getInstance().getStream() << "[" << EnumToString(LogLevel) << "] " << std::string((ScopeLogger::getIndentLevel()) * 2, ' ')


