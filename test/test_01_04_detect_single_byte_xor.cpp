#include <gtest/gtest.h>

#include "01_04_detect_single_byte_xor.hpp"

TEST(detect_single_byte_xor, given_example) {
    const std::string given_input_file = "01_04.txt";
    const std::string given_output = "";
    const char given_key = 0;
    std::string decoded_output = "";

    char scored_key = detect_single_byte_xor(given_input_file, decoded_output);

    ASSERT_EQ(scored_key, given_key);
    ASSERT_EQ(given_output, decoded_output);
}
