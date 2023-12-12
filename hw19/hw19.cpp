#include <iostream>
#include <vector>
#include <map>

//20.16
int main() {
    // �������� ������� ����� ����� V
    std::vector<int> V;
    int n;
    std::cout << "Enter the size of the vector: ";
    std::cin >> n;

    std::cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; ++i) {
        int element;
        std::cin >> element;
        V.push_back(element);
    }

    // ���������� �������� ������� �� ��������� ������
    std::map<int, std::vector<int>> M;
    for (const auto& element : V) {
        int lastDigit = element % 10;
        M[lastDigit].push_back(element);
    }

    // ��������� ����������
    std::cout << "Grouping result:" << std::endl;
    for (const auto& entry : M) {
        std::cout << entry.first << ": ";
        for (const auto& value : entry.second) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
