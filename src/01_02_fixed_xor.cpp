#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>

/* Set 1 Challenge 2: Fixed XOR
 * Write a function that takes two equal-length buffers and produces their XOR
 * combination.
 *
 * feed it this string "1c0111001f010100061a024b53535009181c"
 * after hex decoding, when XOR'd against "686974207468652062756c6c277320657965"
 * should produce "746865206b696420646f6e277420706c6179"
 *
 * XOR can be done using '^' between numbers. Reading the data in similar to 01
 * _01 can be used to produce a byte array. This can be XOR'd per byte with the
 * second provided input of bytes. It looks like both inputs are hex (base 16)
 * and the output is also hex (base 16).
 */

static const uint8_t hex_chars[16] = { '0', '1', '2', '3', '4', '5',
                                       '6', '7', '8', '9', 'a', 'b',
                                       'c', 'd', 'e', 'f' };

void fixed_xor(const std::string& hex_string_a, 
               const std::string& hex_string_b, 
               std::string& xor_output) {
    std::vector<uint8_t> byte_array_a;
    std::vector<uint8_t> byte_array_b;
    std::vector<uint8_t> xor_byte_array;

    if (hex_string_a.length() != hex_string_b.length()) {
        return;
    }

    for (uint32_t i = 0; i < hex_string_a.length(); i += 2) {
        std::string byte_string_a = hex_string_a.substr(i, 2);
        std::string byte_string_b = hex_string_b.substr(i, 2);
        uint8_t byte_a = static_cast<uint8_t>(std::strtoul(byte_string_a.c_str(), NULL, 16));
        uint8_t byte_b = static_cast<uint8_t>(std::strtoul(byte_string_b.c_str(), NULL, 16));
        byte_array_a.push_back(byte_a);
        byte_array_b.push_back(byte_b);
    }

    std::vector<uint8_t>::iterator it_a = byte_array_a.begin();
    std::vector<uint8_t>::iterator it_b = byte_array_b.begin();
    uint8_t temp_byte = 0U;
    while (it_a != byte_array_a.end()) {
        temp_byte = *it_a ^ *it_b;
        xor_byte_array.push_back(temp_byte);
        it_a++;
        it_b++;
    }
    for (uint8_t byte : xor_byte_array) {
        xor_output += hex_chars[(byte & 0xf0) >> 4];
        xor_output += hex_chars[(byte & 0x0f)];
    }
}

