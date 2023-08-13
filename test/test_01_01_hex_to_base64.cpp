#include <gtest/gtest.h>

#include "01_01_hex_to_base64.hpp"

TEST(hex_to_base64, given_example) {
  const std::string given_input =
      "49276d206b696c6c696e6720796f7572206272616"
      "96e206c696b65206120706f69736f6e6f7573206d"
      "757368726f6f6d";
  const std::string given_output =
      "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEg"
      "cG9pc29ub3VzIG11c2hyb29t";
  std::string converted_output = "";

  hex_to_base64(given_input, converted_output);

  ASSERT_EQ(given_output, converted_output);
}
