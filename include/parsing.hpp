#pragma once

#include <boost/json.hpp>
#include "Logger.hpp"
namespace json = boost::json;

class Parser
{   public:
    [[nodiscard]] static auto parse(const std::string_view& str) -> json::value;
};
