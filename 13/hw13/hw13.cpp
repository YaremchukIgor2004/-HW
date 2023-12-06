#include <iostream>
#include <fstream>
#include <regex> // Пошук рядків в тексті на основі шаблонів

//13.25
int main() {
    std::ifstream inputFile("file.txt");
    std::ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        std::cerr << "Unable to open file!" << std::endl;
        return 1;
    }

    std::regex pattern("\\b\\d{8}\\b");

    std::string line;
    while (std::getline(inputFile, line)) {
        std::sregex_iterator it(line.begin(), line.end(), pattern);
        std::sregex_iterator end;

        while (it != end) {
            std::smatch match = *it;
            std::string dateStr = match.str();
            int day = std::stoi(dateStr.substr(0, 2));
            int month = std::stoi(dateStr.substr(2, 2));
            int year = std::stoi(dateStr.substr(4, 4));

            if (day >= 1 && day <= 31 && month >= 1 && month <= 12) {
                outputFile << dateStr.substr(0, 2) << "-"
                    << dateStr.substr(2, 2) << "-"
                    << dateStr.substr(4, 4) << std::endl;
            }
            else {
                std::cerr << "Invalid date: " << dateStr << std::endl;
            }

            it++;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
