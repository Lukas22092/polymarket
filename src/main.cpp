#include "Connection.hpp"
#include "Logger.hpp"

#include <thread>
#include <chrono>

auto deep_nested(int depth) -> void {
    LOG_ENTRY;
    if (depth > 0) {
        LOG_THIS(LogLevel::Debug) << "depth: " << depth << "\n";
        deep_nested(depth - 1);
    } else {
        LOG_THIS(LogLevel::Debug) << "Reached the bottom!\n";
    }
}

auto fast_function() -> void {
    LOG_ENTRY;
    LOG_THIS(LogLevel::Debug) << "I am fast.\n";
}

auto slow_function() -> void {
    LOG_ENTRY;
    LOG_THIS(LogLevel::Debug) << "Doing some heavy work....\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    LOG_THIS(LogLevel::Debug) << "done.\n";
}

auto main() -> int {
    // 1. Einfacher Start
    LOG_THIS(LogLevel::Debug) << "Starting the trace test...\n";

    deep_nested(3);

    fast_function();
    slow_function();

    LOG_THIS(LogLevel::Debug) << "Trace test finished.\n";
    
    return 0;
}