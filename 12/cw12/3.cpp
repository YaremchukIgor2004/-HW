#include <iostream>
#include <cmath>
#include <iomanip>

// Lab 12 task 3

int main() {
    constexpr size_t MAX_NUM_WIDTH = 8;

    size_t n;
    std::cin >> n;

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1); // one extra for '\n'

    std::cout << '\n';

    std::cout.fill(' ');

    for (size_t i = 1; i <= n; i++) {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << i;
    }
    std::cout << '\n';

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);

    std::cout << '\n';

    std::cout.fill(' ');

    std::cout << std::setprecision(MAX_NUM_WIDTH - 2);

    for (size_t i = 1; i <= n; i++) {
        std::cout.width(MAX_NUM_WIDTH);
        std::cout << std::sqrt(i);
    }
    std::cout << '\n';

    std::cout.fill('+');
    std::cout.width(n * MAX_NUM_WIDTH + 1);

    std::cout << '\n';
}