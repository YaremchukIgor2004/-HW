#include <iostream>
#include <fstream>
#include <vector>

//11.3.g
bool isPalindrome(int number) {
    int original = number;
    int reverse = 0;

    while (number > 0) {
        int digit = number % 10;
        reverse = reverse * 10 + digit;
        number /= 10;
    }

    return original == reverse;
}

int main() {
    std::ofstream fileF("F.txt");
    if (!fileF.is_open()) {
        std::cerr << "Unable to open file F.txt" << std::endl;
        return 1;
    }

    std::cout << "Enter integers into file F. Enter 0 to stop." << std::endl;

    int input;
    while (true) {
        std::cin >> input;
        if (input == 0) {
            break;
        }
        fileF << input << " ";
    }

    fileF.close();

    std::ifstream fileFRead("F.txt");
    if (!fileFRead.is_open()) {
        std::cerr << "Unable to open file F.txt for reading" << std::endl;
        return 1;
    }

    std::ofstream fileG("G.txt");
    if (!fileG.is_open()) {
        std::cerr << "Unable to open file G.txt" << std::endl;
        return 1;
    }

    int number;
    while (fileFRead >> number) {
        if (isPalindrome(number)) {
            fileG << number << " ";
        }
    }

    fileFRead.close();
    fileG.close();

    std::cout << "Palindromes have been written to file G.txt." << std::endl;

    return 0;
}
