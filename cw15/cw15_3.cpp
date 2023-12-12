#include <iostream>

class Polynomial {
private:
    int power;
    double* coefficients;

public:
    Polynomial(int deg) : power(deg), coefficients(new double[deg + 1]) {}

    Polynomial(const Polynomial& other) : power(other.power), coefficients(new double[other.power + 1]) {
        for (int i = 0; i <= power; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    void fillCoefficientsViaConstructor() {
        std::cout << "Enter the coefficients of the polynomial:" << std::endl;
        for (int i = power; i >= 0; --i) {
            std::cout << "Coefficient for x^" << i << ": ";
            std::cin >> coefficients[i];
        }
    }

    void setCoefficient(int index, double value) {
        if (index >= 0 && index <= power) {
            coefficients[index] = value;
        }
        else {
            std::cerr << "Invalid coefficient index." << std::endl;
        }
    }

    void display() const {
        std::cout << "Polynomial: ";
        for (int i = power; i >= 0; --i) {
            std::cout << coefficients[i];
            if (i > 0) {
                std::cout << "x^" << i << " + ";
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int power;
    std::cout << "Enter the power of the polynomial: ";
    std::cin >> power;

    Polynomial poly1(power);
    poly1.fillCoefficientsViaConstructor();

    std::cout << "Polynomial created using constructor:" << std::endl;
    poly1.display();

    Polynomial poly2 = poly1;
    poly2.setCoefficient(2, 10.0);

    std::cout << "Original Polynomial:" << std::endl;
    poly1.display();

    std::cout << "Modified Polynomial:" << std::endl;
    poly2.display();

    return 0;
}