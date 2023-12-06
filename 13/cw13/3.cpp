#include <iostream>
#include <cctype>
#include <string>
#include <string_view>

// Lab 13 task 3

std::string trim_words(std::string_view s) {
    bool is_word = false;
    std::string ret;
    char prev = '\0';
    for (auto ch : s) {
        bool is_word_char = std::isalnum(static_cast<unsigned char>(ch));
        if (is_word_char && is_word || !is_word) {
            ret += prev;
        }
        prev = ch;
        is_word = is_word_char;
    }
    return ret;
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << '`' << trim_words(s) << '`' << '\n';
}