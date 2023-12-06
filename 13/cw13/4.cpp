#include <iostream>
#include <string_view>
#include <vector>
#include <charconv>

// Lab 13 task 4

std::vector<int> ints_from_string_with_sep(std::string_view s, std::string_view sep) {
    std::vector<int> ret{};
    if (s.substr(0, sep.size()) == sep) s.remove_prefix(sep.size());
    while (!s.empty()) {
        int num{};
        auto [ptr, ec] = std::from_chars(s.data(), s.data() + s.size(), num);
        ret.push_back(num);
        s = s.substr(ptr - s.data());
        s = s.substr(s.find(sep));
    }
    return ret;
}

int main() {
    auto a = ints_from_string_with_sep("42, 26", ", ");
}