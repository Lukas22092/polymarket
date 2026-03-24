#include <string>

template<typename E>
auto EnumToString(E enum_) -> std::string 
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
auto EnumToString(log_level enum_) -> std::string
{
    switch(enum_)
    {
        case Trace : return "Trace";
        case Debug : return "Debug";
        case Error : return "Error";
    }
}
