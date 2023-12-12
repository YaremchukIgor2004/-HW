#include <iostream>
#include <vector>
#include <cmath>

class Vector {
private:
    std::vector<double> components;

public:
    Vector(int dimensions) : components(dimensions) {}

    double& operator[](int index) {
        return components[index];
    }

    double operator[](int index) const {
        return components[index];
    }

    int size() const {
        return components.size();
    }

    double calculate_norm() const {
        double norm = 0.0;
        for (int i = 0; i < size(); i++) {
            norm += pow(components[i], 2);
        }
        return std::sqrt(norm);
    }
};

Vector input_vector() {
    int dimensions;
    std::cout << "input dimension(d): ";
    std::cin >> dimensions;

    Vector vector(dimensions);

    std::cout << "input coordinates: " << std::endl;
    for (int i = 0; i < dimensions; i++) {
        std::cin >> vector[i];
    }

    return vector;
}

double sum_of_norms(const std::vector<Vector>& vectors) {
    double sum = 0.0;
    for (const Vector& vector : vectors) {
        sum += vector.calculate_norm();
    }
    return sum;
}

int main() {
    int n;
    std::cout << "input count of vectors(n): ";
    std::cin >> n;

    std::vector<Vector> vectors;

    for (int i = 0; i < n; i++) {
        std::cout << "vector " << i + 1 << ":" << std::endl;
        Vector vector = input_vector();
        vectors.push_back(vector);
    }

    double sum = sum_of_norms(vectors);

    std::cout << "Sum of norms of vectors: " << sum << std::endl;

    return 0;
}