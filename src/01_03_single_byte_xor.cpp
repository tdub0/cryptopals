#include "01_03_single_byte_xor.hpp"

#include <cctype>
#include <iostream>
#include <unordered_map>

#include "string_interaction.hpp"

/* Set 1 Challenge 3: Single-byte XOR cipher
 *
 * Given a hex encoded string, find the single character that has been XOR'd
 * against the message. Devise a method to "score" a piece of English plaintext.
 * Hint indicates character frequency is a good metric. Evaluate each output and
 * choose the one with the best score.
 *
 * Wikipedia (en.wikipedia.org/wiki/Letter_frequency) lists relative frequency
 */

// from http://en.algoritmy.net/article/40379/Letter-frequency-English
static const std::unordered_map<uint8_t, double> char_freq = {
    {'a', 8.167}, {'b', 1.492}, {'c', 2.782}, {'d', 4.253}, {'e', 12.702}, {'f', 2.228},
    {'g', 2.015}, {'h', 6.094}, {'i', 6.966}, {'j', 0.153}, {'k', 0.772},  {'l', 4.025},
    {'m', 2.406}, {'n', 6.749}, {'o', 7.507}, {'p', 1.929}, {'q', 0.095},  {'r', 5.987},
    {'s', 6.327}, {'t', 9.056}, {'u', 2.758}, {'v', 0.978}, {'w', 2.360},  {'x', 0.150},
    {'y', 1.974}, {'z', 0.074}};

char single_byte_xor(const std::string& hex_string) {
    char key = 0;
    std::vector<uint8_t> byte_array;
    std::vector<uint8_t> byte_array_copy;

    if (hex_from_string(hex_string, byte_array) == status::error) {
        std::cout << "hex_from_string error" << '\n';
        return key;
    }

    for (uint8_t& c : byte_array) {
        c = std::tolower(c);
    }

    uint32_t max_score = 0;
    uint32_t current_score = 0;
    for (uint32_t xor_char = 'a'; xor_char <= 'z'; xor_char++) {
        current_score = 0;
        byte_array_copy = byte_array;
        for (uint8_t& c : byte_array_copy) {
            c = std::tolower(c ^ xor_char);
            if (c == ' ') current_score += 15;
            if (c < 'a' || c > 'z') c = ' ';
            if (!std::isalpha(c)) continue;
            current_score += char_freq.at(c);
        }
        std::cout << "string [" << xor_char << "]: ";
        for (uint8_t c : byte_array_copy) {
            std::cout << c;
        }
        std::cout << "  score: " << current_score << '\n';
        if (current_score > max_score) {
            max_score = current_score;
            key = static_cast<char>(xor_char);
            std::cout << "max_score: " << max_score << '\n';
        }
    }
    return key;
}
