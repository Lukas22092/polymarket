#pragma once
#include <string>

template<typename E>
inline auto EnumToString(E enum_) -> std::string 
{
    return "UNKNOWN ENUM";
};

enum LogLevel
{
    Trace,
    Debug,
    Error,
    Warn,
};

template<>
inline auto EnumToString(LogLevel enum_) -> std::string
{
    switch(enum_)
    {
        case Trace : return "Trace";
        case Debug : return "Debug";
        case Error : return "Error";
        case Warn: return "Warn";
        default: return "UNKNOWN ENUM";
    }
}
