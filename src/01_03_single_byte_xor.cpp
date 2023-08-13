#include "01_03_single_byte_xor.hpp"

#include "string_interaction.hpp"

char single_byte_xor(const std::string& hex_string) {
  char key = 0;
  std::vector<uint8_t> byte_array;

  if (hex_from_string(hex_string, byte_array) == status::error) {
    return key;
  }

  return key;
}
