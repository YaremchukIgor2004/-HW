#include <iostream>
#include <cassert>
#include <cmath>
#include <stdexcept>

int charToDigit(char ch, int v) {
    assert((ch >= '0' && ch <= '9' && ch - '0' < v) ||
        (ch >= 'A' && ch <= 'F' && ch - 'A' + 10 < v) ||
        (ch >= 'a' && ch <= 'f' && ch - 'a' + 10 < v));

    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    else if (ch >= 'A' && ch <= 'F') {
        return ch - 'A' + 10;
    }
    else {
        return ch - 'a' + 10;
    }
}

int convertToDecimal(const std::string& str, int base) {
    assert(base >= 2 && base <= 16);

    int result = 0;
    int power = str.length() - 1;

    for (char ch : str) {
        int digit = charToDigit(ch, base);
        result += digit * std::pow(base, power);
        --power;
    }

    return result;
}

int main() {
    try {
        std::string input;
        int base;

        std::cout << "Enter a number in a given base (2-16): ";
        std::cin >> input;

        std::cout << "Enter the base (2-16): ";
        std::cin >> base;

        int result = convertToDecimal(input, base);
        std::cout << "Decimal equivalent: " << result << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}