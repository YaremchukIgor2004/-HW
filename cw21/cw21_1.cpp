#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<int> read_vector_from_file(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (!file.is_open()) {
        throw std::runtime_error("error open file.");
    }

    int size;
    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    std::vector<int> vec(size);
    file.read(reinterpret_cast<char*>(vec.data()), size * sizeof(int));

    file.close();
    return vec;
}

int main() {
    try {
        std::vector<int> V0 = read_vector_from_file("vectors.bin");

        int N;
        std::ifstream configFile("20_9.bin", std::ios::binary | std::ios::in);
        configFile.read(reinterpret_cast<char*>(&N), sizeof(N));
        configFile.close();

        int matchingVectors = 0;
        for (int i = 1; i <= N; i++) {
            std::vector<int> Vi = read_vector_from_file(("V" + std::to_string(i) + ".bin").c_str());

            if (std::include(Vi.begin(), Vi.end(), V0.begin(), V0.end())) {
                ++matchingVectors;
            }
        }

        std::cout << "count of vectors that include all components of V0: " << matchingVectors << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "error 404: " << e.what() << std::endl;
    }

    return 0;
}