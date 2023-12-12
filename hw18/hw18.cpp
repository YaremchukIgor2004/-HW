#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//20.11
int main() {
    // Заданий рядок name
    std::string name = "output.txt";

    // Заданий вектор V з парною кількістю цілих елементів
    std::vector<int> V = { 1, 2, 3, 4, 5, 6, 4, 3, 8, 9 };

    // Знаходження середини вектора
    size_t middle = V.size() / 2;

    // Розділення вектора на першу та другу половини
    std::vector<int> first_half(V.begin(), V.begin() + middle);
    std::vector<int> second_half(V.begin() + middle, V.end());

    // Сортування обох половин
    std::sort(first_half.begin(), first_half.end());
    std::sort(second_half.begin(), second_half.end());

    // Використання set_difference для знаходження різниці
    std::vector<int> difference;
    std::set_difference(second_half.begin(), second_half.end(),
        first_half.begin(), first_half.end(),
        std::inserter(difference, difference.begin()));

    // Запис у текстовий файл
    std::ofstream output_file(name);
    if (output_file.is_open()) {
        for (const auto& num : difference) {
            output_file << num << std::endl;
        }
        output_file.close();
        std::cout << "The result is recorded in a file " << name << std::endl;
    }
    else {
        std::cerr << "Could not open file for writing." << std::endl;
        return 1;
    }

    return 0;
}
