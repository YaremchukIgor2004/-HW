#include <iostream>
#include <string>
#include <string_view>

// Lab 13 task 1

constexpr std::string_view target_substr(std::string_view s) {
    const size_t colon = s.find(':');
    if (colon == std::string_view::npos) return s;
    const size_t r = colon + 1;
    return s.substr(r, s.find(',', r) - r);
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    std::cout << '`' << target_substr(s) << '`' << '\n';
}