#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

/* Set 1 Challenge 1: Convert hex to base64
 *
 * Take triplet of bytes (24 bits) and convert to 4 6-bit octets
 *  example:
 *      0x 4d       | 61       | 63
 *      0b 01001101 | 01100001 | 01101110
 *      0b 010011 | 01 0110 | 0001 01 | 101110
 *      i  19     | 22      | 5       | 46
 *     b64 T      | W       | F       | u
 *
 *  From the example, do the following on each pair of triplex hex octets.
 *  Octets are referenced as octet2, octet1, and octet0:
 *      base64_3 = (octet2 & 0xfc)
 *      base64_2 = ((octet2 & 0x3) << 4) | (octet1 & 0xf0)
 *      base64_1 = ((octet1 & 0xf) << 2) | (octet0 & 0xc0)
 *      base64_0 = (octet0 & 0x3f)
 *  Then convert using using a base64_chars index
 */

static const std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz"
                                        "0123456789+/";

void hex_to_base64(const std::string& hex_string, std::string& base64_string) {
    std::vector<uint8_t> byte_array;
    std::vector<uint8_t> b64_array;

    for (uint32_t i = 0; i < hex_string.length(); i += 2) {
        std::string byte_string = hex_string.substr(i, 2);
        uint8_t byte = static_cast<uint8_t>(std::strtoul(byte_string.c_str(), NULL, 16));
        byte_array.push_back(byte);
    }

    for (uint32_t i = 0; i < byte_array.size(); i += 3) {
        b64_array.push_back((byte_array[i] & 0xfc) >> 2);
        b64_array.push_back(((byte_array[i] & 0x03) << 4 ) | ((byte_array[i+1] & 0xf0) >> 4));
        b64_array.push_back(((byte_array[i+1] & 0x0f) << 2) | ((byte_array[i+2] & 0xc0) >> 6));
        b64_array.push_back(byte_array[i+2] & 0x3f);
    }

    for (uint8_t b64_byte : b64_array) {
        base64_string.push_back(base64_chars[b64_byte]);
    }
}

