#include <iostream>
#include <sstream>
#include <stdexcept>

//18.6
template <typename T>
class Rational {
private:
    T numerator;
    T denominator;

public:
    Rational(T num, T den) : numerator(num), denominator(den) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
        simplify();
    }

    // Helper function to find the greatest common divisor
    T gcd(T a, T b) const {
        while (b != 0) {
            T temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Helper function to simplify the rational number
    void simplify() {
        T common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;

        // Make sure the denominator is positive
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    // Overloaded arithmetic operators
    Rational<T> operator+(const Rational<T>& other) const {
        return Rational<T>(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Rational<T> operator-(const Rational<T>& other) const {
        return Rational<T>(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Rational<T> operator*(const Rational<T>& other) const {
        return Rational<T>(numerator * other.numerator, denominator * other.denominator);
    }

    Rational<T> operator/(const Rational<T>& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by zero.");
        }
        return Rational<T>(numerator * other.denominator, denominator * other.numerator);
    }

    // Overloaded comparison operators
    bool operator==(const Rational<T>& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator!=(const Rational<T>& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational<T>& other) const {
        return (numerator * other.denominator) < (other.numerator * denominator);
    }

    bool operator<=(const Rational<T>& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Rational<T>& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Rational<T>& other) const {
        return !(*this < other);
    }

    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& os, const Rational<T>& rational) {
        os << rational.numerator << " / " << rational.denominator;
        return os;
    }

    // Overloaded input operator
    friend std::istream& operator>>(std::istream& is, Rational<T>& rational) {
        char slash;
        is >> rational.numerator >> slash >> rational.denominator;
        if (!is || slash != '/') {
            is.setstate(std::ios::failbit);
        }
        else {
            rational.simplify();
        }
        return is;
    }
};

// Specialization for the case when numerator or denominator is a string
template <>
class Rational<std::string> {
private:
    std::string numerator;
    std::string denominator;

public:
    Rational(std::string num, std::string den) : numerator(num), denominator(den) {
        if (denominator == "0") {
            throw std::invalid_argument("Denominator cannot be zero.");
        }
    }

    // Concatenation for addition
    Rational<std::string> operator+(const Rational<std::string>& other) const {
        return Rational<std::string>(numerator + " + " + other.numerator,
            denominator + " + " + other.denominator);
    }

    // Non-implemented arithmetic operators for strings
    Rational<std::string> operator-(const Rational<std::string>& other) const {
        throw std::invalid_argument("Subtraction is not supported for string numerators/denominators.");
    }

    Rational<std::string> operator*(const Rational<std::string>& other) const {
        throw std::invalid_argument("Multiplication is not supported for string numerators/denominators.");
    }

    Rational<std::string> operator/(const Rational<std::string>& other) const {
        throw std::invalid_argument("Division is not supported for string numerators/denominators.");
    }

    // Public accessor methods for numerator and denominator
    const std::string& getNumerator() const {
        return numerator;
    }

    const std::string& getDenominator() const {
        return denominator;
    }

    // Overloaded comparison operators
    bool operator==(const Rational<std::string>& other) const {
        return (numerator == other.numerator) && (denominator == other.denominator);
    }

    bool operator!=(const Rational<std::string>& other) const {
        return !(*this == other);
    }

    bool operator<(const Rational<std::string>& other) const {
        return (numerator + denominator) < (other.numerator + other.denominator);
    }

    bool operator<=(const Rational<std::string>& other) const {
        return (*this < other) || (*this == other);
    }

    bool operator>(const Rational<std::string>& other) const {
        return !(*this <= other);
    }

    bool operator>=(const Rational<std::string>& other) const {
        return !(*this < other);
    }

    // Overloaded output operator
    friend std::ostream& operator<<(std::ostream& os, const Rational<std::string>& rational) {
        os << rational.numerator << " / " << rational.denominator;
        return os;
    }

    // Overloaded input operator
    friend std::istream& operator>>(std::istream& is, Rational<std::string>& rational) {
        char slash;
        is >> rational.numerator >> slash >> rational.denominator;
        if (!is || slash != '/') {
            is.setstate(std::ios::failbit);
        }
        return is;
    }
};

int main() {
    try {
        // Example usage for integer numerator/denominator
        Rational<int> r1(1, 2);
        Rational<int> r2(3, 4);

        std::cout << "r1 + r2: " << r1 + r2 << std::endl;
        std::cout << "r1 - r2: " << r1 - r2 << std::endl;
        std::cout << "r1 * r2: " << r1 * r2 << std::endl;
        std::cout << "r1 / r2: " << r1 / r2 << std::endl;

        std::cout << "r1 == r2: " << (r1 == r2) << std::endl;
        std::cout << "r1 != r2: " << (r1 != r2) << std::endl;
        std::cout << "r1 < r2: " << (r1 < r2) << std::endl;
        std::cout << "r1 <= r2: " << (r1 <= r2) << std::endl;
        std::cout << "r1 > r2: " << (r1 > r2) << std::endl;
        std::cout << "r1 >= r2: " << (r1 >= r2) << std::endl;

        // Example usage for string numerator/denominator
        Rational<std::string> sr1("1", "2");
        Rational<std::string> sr2("3", "4");

        std::cout << "sr1 + sr2: " << sr1 + sr2 << std::endl;
        std::cout << "sr1 - sr2: " << sr1 - sr2 << std::endl;
        std::cout << "sr1 * sr2: " << sr1 * sr2 << std::endl;
        std::cout << "sr1 / sr2: " << sr1 / sr2 << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
