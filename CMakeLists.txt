cmake_minimum_required(VERSION 3.26)
project(cryptopals)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(
        -Wall -Werror -Wextra -pedantic)
endif()

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.14.0
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_EXPORT_COMPILE_COMMANDS)

enable_testing()

add_executable(test_01_01_hex_to_base64
    src/string_interaction.cpp
    src/01_01_hex_to_base64.cpp
    test/test_01_01_hex_to_base64.cpp)
add_executable(test_01_02_fixed_xor
    src/string_interaction.cpp
    src/01_02_fixed_xor.cpp
    test/test_01_02_fixed_xor.cpp)

target_include_directories(test_01_01_hex_to_base64
    PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_include_directories(test_01_02_fixed_xor
    PRIVATE ${PROJECT_SOURCE_DIR}/include)

target_link_libraries(test_01_01_hex_to_base64 GTest::gtest_main)
target_link_libraries(test_01_02_fixed_xor GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_01_01_hex_to_base64)
gtest_discover_tests(test_01_02_fixed_xor)

