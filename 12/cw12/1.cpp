#include <iostream>
#include <iomanip>
#include <cmath>

// Lab 12 task 1

int main() {
    double x, y;
    std::cin >> x >> y;
    double ans = std::pow(x, y);
    std::cout << "x ^ y = " << ans << '\n'
        << "x ^ y = " << std::scientific << ans << '\n';

}