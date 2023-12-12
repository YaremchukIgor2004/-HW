#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

//20.11
int main() {
    // ������� ����� name
    std::string name = "output.txt";

    // ������� ������ V � ������ ������� ����� ��������
    std::vector<int> V = { 1, 2, 3, 4, 5, 6, 4, 3, 8, 9 };

    // ����������� �������� �������
    size_t middle = V.size() / 2;

    // ��������� ������� �� ����� �� ����� ��������
    std::vector<int> first_half(V.begin(), V.begin() + middle);
    std::vector<int> second_half(V.begin() + middle, V.end());

    // ���������� ���� �������
    std::sort(first_half.begin(), first_half.end());
    std::sort(second_half.begin(), second_half.end());

    // ������������ set_difference ��� ����������� ������
    std::vector<int> difference;
    std::set_difference(second_half.begin(), second_half.end(),
        first_half.begin(), first_half.end(),
        std::inserter(difference, difference.begin()));

    // ����� � ��������� ����
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
