#include "parsing.hpp"





auto Parser::parse(const std::string_view &str) -> json::value
{
    LOG_ENTRY;
    return json::parse(str);
}