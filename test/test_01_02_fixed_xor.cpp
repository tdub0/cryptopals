#include <gtest/gtest.h>

#include "01_02_fixed_xor.hpp"

TEST(fixed_xor, given_example) {
  const std::string given_input_a = "1c0111001f010100061a024b53535009181c";
  const std::string given_input_b = "686974207468652062756c6c277320657965";
  const std::string given_output = "746865206b696420646f6e277420706c6179";
  std::string converted_output = "";

  fixed_xor(given_input_a, given_input_b, converted_output);

  ASSERT_EQ(given_output, converted_output);
}
