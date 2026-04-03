cmake_minimum_required(VERSION 3.10)
project(polymarket LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

# Dependencies
find_package(fmt CONFIG REQUIRED)
find_package(Boost REQUIRED COMPONENTS system) 
find_package(OpenSSL REQUIRED)

# GTest Setup
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

# For Windows: prevent GTest from overriding your compiler settings
if(WIN32)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)

# Project Sources
set(SOURCES
    src/main.cpp
    src/Logger.cpp
    src/Connection.cpp
    src/EventHandler.cpp  # Added this missing file
)

add_executable(polymarket ${SOURCES})
target_include_directories(polymarket PRIVATE include)
set_property(TARGET polymarket PROPERTY COMPILE_WARNING_AS_ERROR ON)

target_link_libraries(polymarket PRIVATE 
    Boost::boost
    OpenSSL::SSL
    OpenSSL::Crypto
)

# Testing
enable_testing()
include(GoogleTest)

add_executable(
  hello_test
  tests/hello_test.cpp  # Updated path to match your folder structure
)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

# If your tests need to include files from 'include/', add this:
target_include_directories(hello_test PRIVATE include)

gtest_discover_tests(hello_test)