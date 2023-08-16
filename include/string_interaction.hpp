#ifndef STRING_INTERACTION_H
#define STRING_INTERACTION_H

#include <string>
#include <vector>

enum class status { ok, error };

status hex_from_string(const std::string& hex_input, std::vector<char>& byte_output);

status bytes_to_hex_string(const std::vector<char>& byte_input, std::string& string_output);

#endif
