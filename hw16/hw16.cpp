#include <iostream>
#include <fstream>
#include <vector>

class BinaryFileHandler {
private:
    std::string filename;
    int numberOfNumbers;

public:
    BinaryFileHandler(const std::string& fname, int num)
        : filename(fname), numberOfNumbers(num) {}

    void writeNumbersToFile(const std::vector<int>& numbers) {
        std::ofstream file(filename, std::ios::binary);

        if (!file.is_open()) {
            throw std::ios_base::failure("Unable to create file.");
        }

        file.write(reinterpret_cast<const char*>(numbers.data()), numbers.size() * sizeof(int));
        file.close();
    }

    void readNumbersFromFile(std::vector<int>& numbers) {
        std::ifstream file(filename, std::ios::binary);

        if (!file.is_open()) {
            throw std::ios_base::failure("Unable to open file.");
        }

        numbers.resize(numberOfNumbers);
        file.read(reinterpret_cast<char*>(numbers.data()), numbers.size() * sizeof(int));
        file.close();
    }

    void displayFileContents() {
        std::vector<int> numbers;
        readNumbersFromFile(numbers);

        std::cout << "File Contents:\n";
        for (int num : numbers) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    int getNumberAtIndex(int index) {
        if (index < 0 || index >= numberOfNumbers) {
            throw std::out_of_range("Index out of bounds.");
        }

        std::vector<int> numbers;
        readNumbersFromFile(numbers);

        return numbers[index];
    }

    void addNumbersToEndOfFile(const std::vector<int>& additionalNumbers) {
        std::vector<int> numbers;
        readNumbersFromFile(numbers);

        numbers.insert(numbers.end(), additionalNumbers.begin(), additionalNumbers.end());

        writeNumbersToFile(numbers);
    }

    void deleteNumberAtIndex(int index) {
        if (index < 0 || index >= numberOfNumbers) {
            throw std::out_of_range("Index out of bounds.");
        }

        std::vector<int> numbers;
        readNumbersFromFile(numbers);

        numbers.erase(numbers.begin() + index);

        writeNumbersToFile(numbers);
    }
};

int main() {
    try {
        BinaryFileHandler handler("example.bin", 3);

        // Write numbers to file
        std::vector<int> initialNumbers = { 1, 2, 3 };
        handler.writeNumbersToFile(initialNumbers);

        // Display file contents
        handler.displayFileContents();

        // Access and modify file contents
        std::cout << "Number at index 1: " << handler.getNumberAtIndex(1) << std::endl;

        std::vector<int> additionalNumbers = { 4, 5 };
        handler.addNumbersToEndOfFile(additionalNumbers);

        handler.displayFileContents();

        handler.deleteNumberAtIndex(2);

        handler.displayFileContents();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
