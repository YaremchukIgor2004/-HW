#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>

// Lab 12 task 4

int main() {
    size_t n;
    std::cin >> n;

    std::vector<int> m(n);
    std::vector<double> x(n);

    for (size_t i = 0; i < n; i++) {
        std::cin >> m[i];
    }

    constexpr const char* input_file = "data/lab12_task4_inputs.txt";
    constexpr const char* output_file = "data/lab12_task4_outputs.txt";

    {
        std::ifstream f(input_file);
        if (!f.is_open() || f.bad()) {
            std::cout << "can't open `" << input_file << "`\n";
            return EXIT_FAILURE;
        }

        for (size_t i = 0; i < n; i++) {
            f >> x[i];
        }
    }

    {
        std::ofstream f(output_file);
        if (!f.is_open() || f.bad()) {
            std::cout << "can't open `" << output_file << "`\n";
            return EXIT_FAILURE;
        }

        for (size_t i = 0; i < n; i++) {
            f << std::pow(x[i], m[i]) << ' ';
        }
    }
}