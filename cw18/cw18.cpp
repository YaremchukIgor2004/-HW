#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

template <typename T>
T find_max(T a, T b) {
    return (a > b) ? a : b;
}

//task 2
template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    void push(const T& element) {
        elements.push_back(element);
    }

    T pop() {
        if (!isEmpty()) {
            T topElement = elements.back();
            elements.pop_back();
            return topElement;
        }
        return T();
    }

    bool isEmpty() const {
        return elements.empty();
    }

    size_t size() const {
        return elements.size();
    }
};

template <typename T>
size_t input_mas(Stack<T>& resultStack) {
    T input;
    size_t count = 0;

    do {
        std::cin >> input;
        if (input != 0) {
            resultStack.push(input);
            count++;
        }
    } while (input != 0);

    return count;
}

//task3
template <typename T>
class BlackBox {
private:
    static const size_t MAX_SIZE = 100;
    std::vector<T> elements;

public:
    BlackBox() {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    BlackBox(const T* array, size_t size) {
        if (size > MAX_SIZE) {
            throw std::invalid_argument("Size exceeds the maximum limit.");
        }

        elements.assign(array, array + size);
        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    void push(const T& element) {
        if (elements.size() < MAX_SIZE) {
            elements.push_back(element);
        }
        else {
            throw std::overflow_error("BlackBox is full. Cannot add more elements.");
        }
    }

    T pop() {
        if (elements.empty()) {
            throw std::underflow_error("BlackBox is empty. Cannot pop an element.");
        }

        size_t randomIndex = std::rand() % elements.size();

        T randomElement = elements[randomIndex];

        elements.erase(elements.begin() + randomIndex);

        return randomElement;
    }
};

int main() {
    int task;
    std::cout << "input task: ";
    std::cin >> task;

    switch (task) {
    case 1:
        int type;
        std::cout << "input type of number(lf - 1, d - 2, u - 3): ";
        std::cin >> type;
        if (type == 1) {
            double a, b;
            std::cout << "input first double number: ";
            std::cin >> a;
            std::cout << "input second double number: ";
            std::cin >> b;
            std::cout << "max(" << a << "," << b << ")=" << find_max(a, b);
        }
        if (type == 2) {
            int a, b;
            std::cout << "input first int number: ";
            std::cin >> a;
            std::cout << "input second int number: ";
            std::cin >> b;
            std::cout << "max(" << a << "," << b << ")=" << find_max(a, b);
        }
        if (type == 3) {
            unsigned a, b;
            std::cout << "input first unsigned number: ";
            std::cin >> a;
            std::cout << "input second unsigned number: ";
            std::cin >> b;
            std::cout << "max(" << a << "," << b << ")=" << find_max(a, b);
        }
        break;
    case 2:
        Stack<int> intStack;
        std::cout << "input int masyv under 0: ";

        size_t intCount = input_mas(intStack);

        std::cout << "masyv of int numbers: " << std::endl;
        while (!intStack.isEmpty()) {
            std::cout << intStack.pop() << " ";
        }
        std::cout << "\ncount of numbers: " << intCount << std::endl;

        Stack<double> doubleStack;
        std::cout << "input double masyv under 0: ";

        size_t doubleCount = input_mas(doubleStack);

        std::cout << "\nmasyv of double numbers:" << std::endl;
        while (!doubleStack.isEmpty()) {
            std::cout << doubleStack.pop() << " ";
        }
        std::cout << "\ncount of numbers: " << doubleCount << std::endl;
        break;
    case 3:
        try {
            double intArray[] = { 1, 2, 3 };
            BlackBox<double> intBox(intArray, 3);

            std::cout << "Popped element: " << intBox.pop() << std::endl;

            double doubleArray[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
            BlackBox<double> doubleBox(doubleArray, 5);

            std::cout << "Popped element: " << doubleBox.pop() << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        break;
    }

    return 0;
}