cmake_minimum_required(VERSION 3.26)
project(cryptopals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/ec4fed93217bc2830959bb8e86798c1d86956949.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(test_01_01_hex_to_base64 test/test_01_01_hex_to_base64.cpp)
target_link_libraries(test_01_01_hex_to_base64 GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_01_01_hex_to_base64)

