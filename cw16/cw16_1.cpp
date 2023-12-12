#include <iostream>
#include <fstream>
#include <vector>

class Person {
public:
    std::string name;
    unsigned byear;

    Person() : byear(0) {}

    int input() {
        std::cout << "input name: ";
        std::cin >> name;
        std::cout << "input birth year: ";
        std::cin >> byear;
        return 0;
    }

    void show() {
        std::cout << "Name: " << name << "\nBirth Year: " << byear << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << person.name << " " << person.byear;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Person& person) {
        is >> person.name >> person.byear;
        return is;
    }
};

class Friend : public Person {
public:
    std::string phone_number;

    int input() {
        Person::input();
        std::cout << "input phone number: ";
        std::cin >> phone_number;
        return 0;
    }

    void show() {
        Person::show();
        std::cout << "Phone Number: " << phone_number << std::endl;
    }
};

class PhoneBook {
private:
    std::vector<Friend> friends;

public:
    void create_phone_book() {
        std::ifstream file("phonebook.txt");
        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return;
        }

        Friend friend_input;
        while (file >> friend_input) {
            friends.push_back(friend_input);
        }

        file.close();
    }

    void add_friend(const Friend& friend_entry) {
        friends.push_back(friend_entry);

        // Дописуємо дані в кінець файлу
        std::ofstream file("phonebook.txt", std::ios::app);
        if (file.is_open()) {
            file << friend_entry << std::endl;
            file.close();
        }
        else {
            std::cerr << "Error opening file!" << std::endl;
        }
    }

    std::string find_phone_number(const std::string& name) {
        for (const auto& friend_input : friends) {
            if (friend_input.name == name) {
                return friend_input.phone_number;
            }
        }
        return "Not found";
    }
};

int main() {
    PhoneBook phone_book;

    phone_book.create_phone_book();

    Friend new_friend;
    new_friend.input();
    phone_book.add_friend(new_friend);

    std::string search_name;
    std::cout << "Enter name to search for: ";
    std::cin >> search_name;
    std::string phone_number = phone_book.find_phone_number(search_name);
    std::cout << "Phone number: " << phone_number << std::endl;

    return 0;
}