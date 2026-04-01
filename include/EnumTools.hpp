#pragma once
#include <string>

template<typename E>
inline auto EnumToString(E enum_) -> std::string 
{
    return "UNKNOWN ENUM";
};

enum log_level
{
    Trace,
    Debug,
    Error,
};

template<>
inline auto EnumToString(log_level enum_) -> std::string
{
    switch(enum_)
    {
        case Trace : return "Trace";
        case Debug : return "Debug";
        case Error : return "Error";
        default: return "UNKNOWN ENUM";
    }
}
