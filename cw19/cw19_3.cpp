#include <iostream>
#include <list>
#include <iterator>

template <typename T>
class Polynomial {
private:
    std::list<T> coefficients;

public:
    Polynomial() = default;

    Polynomial(std::initializer_list<T> coeffs) : coefficients(coeffs) {}

    void input_polynom() {
        T coeff;
        std::cout << "input coeficients of polynom(0 for end): ";
        while (std::cin >> coeff && coeff != 0) {
            coefficients.push_back(coeff);
        }
    }

    void output_polynomial() const {
        std::cout << "polynom: ";
        for (const T& coeff : coefficients) {
            std::cout << coeff << " ";
        }
        std::cout << std::endl;
    }

    Polynomial<T> add(const Polynomial<T>& other) const {
        Polynomial<T> result;
        auto it1 = coefficients.begin();
        auto it2 = other.coefficients.begin();

        while (it1 != coefficients.end() || it2 != other.coefficients.end()) {
            T coeff1 = (it1 != coefficients.end()) ? *it1 : 0;
            T coeff2 = (it2 != other.coefficients.end()) ? *it2 : 0;
            result.coefficients.push_back(coeff1 + coeff2);

            if (it1 != coefficients.end()) it1++;
            if (it2 != other.coefficients.end()) it2++;
        }

        return result;
    }

    Polynomial<T> multiply(const Polynomial<T>& other) const {
        Polynomial<T> result;
        int degree = coefficients.size() + other.coefficients.size() - 2;
        result.coefficients.resize(degree + 1, 0);

        auto it1 = coefficients.begin();
        for (int i = 0; it1 != coefficients.end(); it1++, i++) {
            auto it2 = other.coefficients.begin();
            for (int j = 0; it2 != other.coefficients.end(); it2++, j++) {
                result.coefficients[i + j] += (*it1) * (*it2);
            }
        }

        return result;
    }

    T evaluate(const T& x) const {
        T result = 0;
        int power = 0;
        for (const T& coeff : coefficients) {
            result += coeff * std::pow(x, power);
            power++;
        }
        return result;
    }
};

int main() {
    Polynomial<int> poly;
    poly.input_polynom();
    poly.output_polynomial();

    return 0;
}