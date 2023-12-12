#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>

int main() {
    int n, m;
    std::cout << "input dimension of matrix(n, m < 100): ";
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix;
    for (int i = 0; i < n; ++i) {
        std::vector<int> row;
        std::cout << "input " << i + 1 << "(" << m << " elements): ";
        for (int j = 0; j < m; ++j) {
            int element;
            std::cin >> element;
            row.push_back(element);
        }
        matrix.push_back(row);
    }

    std::cout << "start matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::vector<std::pair<int, int>> maxElements;
    for (int i = 0; i < n; i++) {
        auto maxElement = std::max_element(matrix[i].begin(), matrix[i].end());
        int maxIndex = std::distance(matrix[i].begin(), maxElement);
        maxElements.push_back(std::make_pair(*maxElement, maxIndex));
    }

    std::sort(maxElements.begin(), maxElements.end(), std::greater<std::pair<int, int>>());

    std::vector<std::vector<int>> newMatrix(m, std::vector<int>(n));
    for (int i = 0; i < n; ++i) {
        int originalRowIndex = maxElements[i].second;
        newMatrix[i] = matrix[originalRowIndex];
    }

    std::cout << "final matrix:" << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << newMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}