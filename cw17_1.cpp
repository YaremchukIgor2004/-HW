#include <iostream>
#include <fstream>
#include <stdexcept>
#include <numeric>
#include <compare>

class Rational {
public:
    Rational() = default;
    Rational(int nominator, unsigned denominator) : m_nominator(nominator) {
        set_denominator(denominator);
        reduce();
    }

    Rational operator-(const Rational& other) const noexcept {
        return *this + (-other);
    }

    Rational operator/(const Rational& other) const noexcept {
        if (other.m_nominator == 0) {
            throw std::invalid_argument("Division by zero");
        }
        return *this * Rational(other.m_denominator, other.m_nominator);
    }

    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    void set_nominator(int nominator) {
        m_nominator = nominator;
    }

    void set_denominator(unsigned denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        m_denominator = denominator;
    }

    friend Rational operator+(const Rational&, const Rational&) noexcept;
    friend Rational operator-(const Rational&, const Rational&) noexcept;
    friend Rational operator*(const Rational&, const Rational&) noexcept;
    friend Rational operator/(const Rational&, const Rational&) noexcept;

    friend std::strong_ordering operator<=>(const Rational&, const Rational&) noexcept;

    friend std::ostream& operator<<(std::ostream&, const Rational&) noexcept;
    friend std::istream& operator>>(std::istream&, Rational&) noexcept;

    friend void saveToFile(const Rational& rational, const std::string& filename);
};

Rational operator+(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator + b.m_nominator * a.m_denominator;
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator-(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_denominator - b.m_nominator * a.m_denominator;
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator*(const Rational& a, const Rational& b) noexcept {
    int nom = a.m_nominator * b.m_nominator;
    unsigned denom = a.m_denominator * b.m_denominator;
    return Rational(nom, denom);
}

Rational operator/(const Rational& a, const Rational& b) noexcept {
    if (b.m_nominator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    int nom = a.m_nominator * b.m_denominator;
    unsigned denom = a.m_denominator * b.m_nominator;
    return Rational(nom, denom);
}

std::strong_ordering operator<=>(const Rational& a, const Rational& b) noexcept {
    return a.m_nominator * b.m_denominator <=> b.m_nominator * a.m_denominator;
}

std::ostream& operator<<(std::ostream& out, const Rational& r) noexcept {
    return out << r.m_nominator << "/" << r.m_denominator;
}

std::istream& operator>>(std::istream& in, Rational& r) noexcept {
    int nom = 0;
    unsigned denom = 1;
    in >> nom >> denom;
    r = Rational(nom, denom);
    return in;
}

void saveToFile(const Rational& rational, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error opening file for writing");
    }

    file << rational;

    if (!file.good()) {
        throw std::runtime_error("Error writing to file");
    }

    file.close();
}

int main() {
    Rational sum = {};
    Rational eps = Rational(1, 1000);
    Rational neg_eps = Rational(-1, 1000);
    Rational summon = {};
    unsigned i = 0;
    do {
        i += 1;
        summon = Rational(int(i % 2) * 2 - 1, i * i);
        sum = sum + summon;
    } while (summon > eps || summon < neg_eps);
    std::cout << sum;

    try {
        saveToFile(sum, "rational_output.txt");
        std::cout << "\nRational saved to file successfully.\n";
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}