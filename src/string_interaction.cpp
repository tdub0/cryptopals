#include "string_interaction.hpp"

#include <array>
#include <cstdint>

constexpr std::array<char, 16> hex_chars = {'0', '1', '2', '3', '4', '5', '6', '7',
                                            '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

status hex_from_string(const std::string& hex_input, std::vector<char>& byte_output) {
    if (hex_input.length() % 2 == 1) {
        return status::error;
    }

    for (uint32_t i = 0; i < hex_input.length(); i += 2) {
        std::string byte_string = hex_input.substr(i, 2);
        char byte = static_cast<char>(std::stoi(byte_string, nullptr, 16));
        byte_output.push_back(byte);
    }

    return status::ok;
}

status bytes_to_hex_string(const std::vector<char>& byte_input, std::string& string_output) {
    for (char byte : byte_input) {
        string_output += hex_chars[(byte & 0xf0) >> 4];
        string_output += hex_chars[(byte & 0x0f)];
    }

    return status::ok;
}
