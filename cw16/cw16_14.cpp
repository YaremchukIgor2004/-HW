#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

class Address {
public:
    std::string city;
    std::string street;
    int house_number;
    int apartment_number;

    Address() : house_number(0), apartment_number(0) {}

    virtual int input() {
        std::cout << "city: ";
        std::cin >> city;
        std::cout << "street: ";
        std::cin >> street;
        std::cout << "house number: ";
        std::cin >> house_number;
        std::cout << "apartment number: ";
        std::cin >> apartment_number;
        return 0;
    }

    virtual void show() const {
        std::cout << "City: " << city << "\nStreet: " << street << "\nHouse Number: " << house_number
            << "\nApartment Number: " << apartment_number << std::endl;
    }
};

class International_address : public Address {
public:
    std::string country;
    std::string postal_code;

    int input() override {
        Address::input();
        std::cout << "country: ";
        std::cin >> country;
        std::cout << "postal code: ";
        std::cin >> postal_code;
        return 0;
    }

    void show() const override {
        Address::show();
        std::cout << "Country: " << country << "\nPostal Code: " << postal_code << std::endl;
    }
};

int main() {
    std::vector<Address*> addresses;
    int n;

    std::cout << "input the count of addresses: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        std::cout << "Einput details for address " << i + 1 << ":\n";
        Address* address;
        if (i % 2 == 0) {
            address = new Address();
        }
        else {
            address = new International_address();
        }
        address->input();
        addresses.push_back(address);
    }

    std::vector<std::string> cities;
    for (const auto& address : addresses) {
        cities.push_back(address->city);
    }

    std::sort(cities.begin(), cities.end());
    auto most_popular_city = std::max_element(cities.begin(), cities.end(), [=](const auto& a, const auto& b) {
        return std::count(cities.begin(), cities.end(), a) < std::count(cities.begin(), cities.end(), b);
        });

    std::cout << "The most popular city is: " << *most_popular_city << std::endl;

    std::ofstream output_file("addresses.txt");
    for (const auto& address : addresses) {
        if (address->city == *most_popular_city) {
            address->show();
            output_file << "-------------------------\n";
        }
    }
    output_file.close();

    for (const auto& address : addresses) {
        delete address;
    }

    return 0;
}