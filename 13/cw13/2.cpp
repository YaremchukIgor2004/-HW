#include <iostream>
#include <string>
#include <cctype>

// Lab 13 task 2

void remove_mid(std::string& s) {
    const size_t first_dot = s.find('.');
    const size_t last_dot = s.rfind('.');
    if (first_dot == std::string::npos) {
        size_t i = 0;
        while (i < s.size() && std::isspace(static_cast<unsigned char>(s[i]))) i++;
        std::memmove(s.data(), s.data() + i, s.size() - i);
        s.resize(s.size() - i);
        return;
    }
    if (first_dot == last_dot) {
        std::memmove(s.data(), s.data() + first_dot, s.size() - first_dot);
        s.resize(s.size() - first_dot);
        return;
    }
    std::memmove(s.data() + first_dot, s.data() + last_dot, s.size() - last_dot);
    s.resize(s.size() + first_dot - last_dot);
}

int main() {
    std::string s;
    std::getline(std::cin, s);
    remove_mid(s);
    std::cout << s << std::endl;
}