#include <iostream>
#include <fstream>

//11.9.a
void checkSignConsistency(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        exit(1);
    }

    int positiveCount = 0;
    int negativeCount = 0;
    int number;

    while (file >> number) {
        if (number > 0) {
            positiveCount++;
        }
        else if (number < 0) {
            negativeCount++;
        }
    }

    file.close();

    if (positiveCount != negativeCount) {
        std::cout << "The file " << filename << " does not contain an equal number of positive and negative integers." << std::endl;
        exit(0);
    }
}

void processFile(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);
    std::ofstream tempFile("temp.txt");

    if (!inFile.is_open() || !outFile.is_open() || !tempFile.is_open()) {
        std::cerr << "Unable to open one or more files." << std::endl;
        exit(1);
    }

    int prevNumber, currentNumber;
    inFile >> prevNumber;

    while (inFile >> currentNumber) {
        if ((prevNumber > 0 && currentNumber > 0) || (prevNumber < 0 && currentNumber < 0)) {
            tempFile << currentNumber << " ";
        }
        else {
            outFile << prevNumber << " ";
        }
        prevNumber = currentNumber;
    }
    outFile << prevNumber;

    inFile.close();
    outFile.close();
    tempFile.close();

    std::rename("temp.txt", outputFile.c_str());
}

int main() {
    const std::string inputFile = "F.txt";
    const std::string outputFile = "G.txt";

    checkSignConsistency(inputFile);
    processFile(inputFile, outputFile);

    std::cout << "Operation completed successfully." << std::endl;

    return 0;
}
