#include <iostream>
#include <string>

//15.10
class Currency {
private:
    std::string name;
    double value;
    int cents;

public:
    Currency(std::string n, double v, int c) : name(n), value(v), cents(c) {}

    friend std::ostream& operator<<(std::ostream& os, const Currency& currency);
    friend std::istream& operator>>(std::istream& is, Currency& currency);

    friend void exchangeCurrency(Currency& c1, Currency& c2, double exchangeRate);
};

class Product {
private:
    std::string name;
    double cost;
    Currency currency;

public:
    Product(std::string n, double c, const Currency& curr) : name(n), cost(c), currency(curr) {}

    friend std::ostream& operator<<(std::ostream& os, const Product& product);
    friend std::istream& operator>>(std::istream& is, Product& product);
};

std::ostream& operator<<(std::ostream& os, const Currency& currency) {
    os << currency.name << " " << currency.value << " " << currency.cents << " cents";
    return os;
}

std::istream& operator>>(std::istream& is, Currency& currency) {
    is >> currency.name >> currency.value >> currency.cents;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Product& product) {
    os << product.name << " " << product.cost << " " << product.currency;
    return os;
}

std::istream& operator>>(std::istream& is, Product& product) {
    is >> product.name >> product.cost >> product.currency;
    return is;
}

void exchangeCurrency(Currency& c1, Currency& c2, double exchangeRate) {
    c1.value *= exchangeRate;
    c2.value /= exchangeRate;
}

int main() {
    Currency usd("USD", 1.0, 100);
    Currency uah("UAH", 38.0, 0);

    Product laptop("Laptop", 1200.0, usd);

    std::cout << "Before exchange:" << std::endl;
    std::cout << "USD: " << usd << std::endl;
    std::cout << "UAH: " << uah << std::endl;
    std::cout << "Laptop: " << laptop << std::endl;

    exchangeCurrency(usd, uah, 38.0);

    std::cout << "\nAfter exchange:" << std::endl;
    std::cout << "USD: " << usd << std::endl;
    std::cout << "UAH: " << uah << std::endl;
    std::cout << "Laptop: " << laptop << std::endl;

    return 0;
}
