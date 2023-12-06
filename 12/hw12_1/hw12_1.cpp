#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<double> numbers;
    double number;

    while (inputFile >> number) {
        numbers.push_back(number);
    }

    inputFile.close();

    std::ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    for (const double& value : numbers) {
        if (value >= -1.0 && value <= 1.0) {
            double arcsinValue = asin(value);
            outputFile << std::scientific << std::setprecision(15) << arcsinValue << std::endl;
        }
        else {
            outputFile << "Ignored" << std::endl;
        }
    }
    outputFile.close();
    std::cout << "Operation completed successfully." << std::endl;

    return 0;
}
