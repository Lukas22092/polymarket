cmake_minimum_required(VERSION 3.10)
project(polymarket LANGUAGES CXX)


set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system) 
find_package(OpenSSL REQUIRED)

set(SOURCES
    src/main.cpp
    src/Logger.cpp
    src/Connection.cpp
)

add_executable(polymarket ${SOURCES})

target_include_directories(polymarket PRIVATE include)
set_property(TARGET polymarket PROPERTY COMPILE_WARNING_AS_ERROR ON)

target_link_libraries(polymarket PRIVATE 
    fmt::fmt
    Boost::boost
    OpenSSL::SSL
    OpenSSL::Crypto
)