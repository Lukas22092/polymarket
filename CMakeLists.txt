cmake_minimum_required(VERSION 3.10)
project(HelloWorld)

find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system) 
find_package(OpenSSL REQUIRED)

add_executable(HelloWorld helloworld.cpp)

target_link_libraries(HelloWorld PRIVATE 
    fmt::fmt
    Boost::boost
    OpenSSL::SSL
    OpenSSL::Crypto
)