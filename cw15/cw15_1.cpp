#include <iostream>
#include <numeric>
#include <compare>

class RationalNumber {
private:
    int nominator;
    int denominator;

    void reduce() {
        int common_divisor = gcd(nominator, denominator);
        nominator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    RationalNumber() : nominator(1), denominator(1) {
        reduce();
    }

    RationalNumber(int p, int q) : nominator(p), denominator(q) {
        if (denominator != 0) {
            reduce();
        }
    }

    void input() {
        std::cout << "Enter the nominator: ";
        std::cin >> nominator;

        do {
            std::cout << "Enter the denominator (non-zero): ";
            std::cin >> denominator;
        } while (denominator == 0);

        setDenominator(denominator);
    }

    void display() const {
        std::cout << nominator << "/" << denominator << std::endl;
    }

    RationalNumber add(const RationalNumber& other) const {
        return RationalNumber(nominator * other.denominator + other.nominator * denominator,
            denominator * other.denominator);
    }

    RationalNumber multiply(const RationalNumber& other) const {
        return RationalNumber(nominator * other.nominator, denominator * other.denominator);
    }

    int getNominator() const {
        return nominator;
    }

    void setNominator(int p) {
        nominator = p;
        reduce();
    }

    int getDenominator() const {
        return denominator;
    }

    void setDenominator(int q) {
        if (q != 0) {
            denominator = q;
            reduce();
        }
    }

    RationalNumber operator+(const RationalNumber& other) const {
        return add(other);
    }

    RationalNumber operator*(const RationalNumber& other) const {
        return multiply(other);
    }

    bool operator==(const RationalNumber& other) const {
        return (nominator * other.denominator == other.nominator * denominator);
    }

    bool operator<(const RationalNumber& other) const {
        return (nominator * other.denominator < other.nominator * denominator);
    }
};

RationalNumber findMinimum(const RationalNumber* array, int size) {
    RationalNumber minNumber = array[0];

    for (int i = 1; i < size; ++i) {
        if (array[i] < minNumber) {
            minNumber = array[i];
        }
    }

    return minNumber;
}

double calculate_sum(double precision) {
    double sum = 1.0;
    double term = 1.0;
    int sign = -1;

    for (int i = 2; std::abs(term) > precision; ++i) {
        term = sign * 1.0 / (i * i);
        sum += term;
        sign *= -1;
    }

    return sum;
}

int main() {
    const int arraySize = 5;
    RationalNumber array[arraySize] = { RationalNumber(1, 2), RationalNumber(3, 4), RationalNumber(1, 3), RationalNumber(5, 6), RationalNumber(2, 5) };

    RationalNumber minNumber = findMinimum(array, arraySize);
    std::cout << "Minimum rational number in the array: ";
    minNumber.display();

    double precision = 0.01;
    double seriesSum = calculate_sum(precision);
    std::cout << "Sum of the series with precision 0.01: " << seriesSum << std::endl;

    return 0;
}