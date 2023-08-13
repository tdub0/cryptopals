#include "string_interaction.hpp"

status hex_from_string(const std::string& hex_input, std::vector<uint8_t>& byte_output) {
  if (hex_input.length() % 2 == 1) {
    return status::error;
  }

  for (uint32_t i = 0; i < hex_input.length(); i += 2) {
    std::string byte_string = hex_input.substr(i, 2);
    uint8_t byte = static_cast<uint8_t>(std::strtoul(byte_string.c_str(), NULL, 16));
    byte_output.push_back(byte);
  }

  return status::ok;
}

status bytes_to_hex_string(const std::vector<uint8_t>& byte_input, std::string& string_output) {
  for (uint8_t byte : byte_input) {
    string_output += hex_chars[(byte & 0xf0) >> 4];
    string_output += hex_chars[(byte & 0x0f)];
  }

  return status::ok;
}
