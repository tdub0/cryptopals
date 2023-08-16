#include <gtest/gtest.h>

#include "01_03_single_byte_xor.hpp"

TEST(single_byte_xor, given_example) {
    const std::string given_input =
        "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
    const std::string given_output = "Cooking MC's like a pound of bacon";
    const char given_key = 'X';
    std::string decoded_output = "";

    char scored_key = single_byte_xor(given_input, decoded_output);

    ASSERT_EQ(scored_key, given_key);
    ASSERT_EQ(given_output, decoded_output);
}
