#ifndef STRING_INTERACTION_H
#define STRING_INTERACTION_H

#include <cstdint>
#include <string>
#include <vector>

enum class status { ok, error };

const uint8_t hex_chars[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
                               '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

status hex_from_string(const std::string& hex_input, std::vector<uint8_t>& byte_input);

status bytes_to_hex_string(const std::vector<uint8_t>& byte_input, std::string& string_output);

#endif
