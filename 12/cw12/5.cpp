#include <iostream>
#include <iomanip>
#include <fstream>

#include <cstdlib>
#include <cmath>

#include <vector>

// Lab 12 task 5

int main() {
    constexpr const char* input_file = "data/lab12_task5_inputs.txt";
    std::ifstream f(input_file);

    if (!f.is_open() || f.bad()) {
        std::cout << "can't open `" << input_file << "`\n";
        return EXIT_FAILURE;
    }

    std::vector<int> nums;
    int n;
    while (f >> n) {
        nums.push_back(n);
    }

    std::cout << std::setprecision(4);
    for (size_t i = 0; i < nums.size(); i++) {
        std::cout << std::sqrt(nums[nums.size() - 1 - i]) << '\n';
    }
}