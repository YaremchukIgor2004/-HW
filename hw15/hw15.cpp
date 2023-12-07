#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

//14.25
void alignText(const std::string& inputFileName, const std::string& outputFileName, size_t maxLineLength) {
    std::ifstream inputFile(inputFileName);
    std::ofstream outputFile(outputFileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Unable to open files." << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;

    while (std::getline(inputFile, line)) {
        for (size_t i = 0; i < line.length(); i += maxLineLength) {
            lines.push_back(line.substr(i, maxLineLength));
        }
    }

    for (auto& l : lines) {
        l.resize(maxLineLength, ' ');
        outputFile << l << std::endl;
    }

    std::cout << "Text alignment completed." << std::endl;

    inputFile.close();
    outputFile.close();
}

int main() {
    size_t maxLineLength = 80;
    alignText("input.txt", "output.txt", maxLineLength);

    return 0;
}
