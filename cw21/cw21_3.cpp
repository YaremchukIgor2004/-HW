#define _CRT_NO_WARNING_
#include <iostream>
#include<list>
#include<array>
#include <algorithm>
#include <numeric>
#include<vector>
#include <ctime>
#include <cctype>
#include <string>
#include <fstream>
#include<cmath>

class BoolVector {
private:
    std::vector<bool> data;

public:
    BoolVector() = default;

    explicit BoolVector(size_t size) : data(size) {}

    void setBit(size_t index, bool value) {
        if (index < data.size()) {
            data[index] = value;
        }
    }

    bool getBit(size_t index) const {
        return (index < data.size()) ? data[index] : false;
    }

    BoolVector bitwiseAND(const BoolVector& other) const {
        BoolVector result(std::min(data.size(), other.data.size()));
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] = data[i] && other.data[i];
        }
        return result;
    }

    BoolVector bitwiseOR(const BoolVector& other) const {
        BoolVector result(std::min(data.size(), other.data.size()));
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] = data[i] || other.data[i];
        }
        return result;
    }

    BoolVector bitwiseNOT() const {
        BoolVector result(data.size());
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] = !data[i];
        }
        return result;
    }

    size_t countOnes() const {
        return std::count(data.begin(), data.end(), true);
    }

    size_t countZeros() const {
        return std::count(data.begin(), data.end(), false);
    }
};

void task1() {
    BoolVector bv1(5);
    bv1.setBit(0, true);
    bv1.setBit(2, true);
    bv1.setBit(4, true);

    BoolVector bv2(5);
    bv2.setBit(1, true);
    bv2.setBit(3, true);
    bv2.setBit(4, true);

    BoolVector resultAND = bv1.bitwiseAND(bv2);
    BoolVector resultOR = bv1.bitwiseOR(bv2);
    BoolVector resultNOT = bv1.bitwiseNOT();

    std::cout << "bv1: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << bv1.getBit(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "bv2: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << bv2.getBit(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "bv1 AND bv2: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << resultAND.getBit(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "bv1 OR bv2: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << resultOR.getBit(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "NOT bv1: ";
    for (size_t i = 0; i < 5; ++i) {
        std::cout << resultNOT.getBit(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of ones in bv1: " << bv1.countOnes() << std::endl;
    std::cout << "Number of zeros in bv1: " << bv1.countZeros() << std::endl;
}

void task2() {
    std::list<int> sp;
    int n;
    int X;
    std::cout << "n = ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        sp.push_back(tmp);
    }
    std::cout << "X = ";
    std::cin >> X;

    sp.sort([X](int x, int y) {
        return(x < X) != (y < X) ? (x < y) : false;
        });

    std::cout << "\n";
    for (auto s : sp) {
        std::cout << s << ", ";
    }
}

void task3() {
    std::vector<int> sp;
    int n;
    int k;
    std::cout << "n = ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp;
        std::cin >> tmp;
        sp.push_back(tmp);
    }
    std::vector<int>sp1 = sp;
    std::cout << "k = ";
    std::cin >> k;
    int s = 0;
    for (int i = 0; i < k; i++) {
        auto max = *std::max_element(sp.begin(), sp.end());
        s += max;
        auto m = std::find(sp.begin(), sp.end(), max);
        sp.erase(m);
    }
    std::cout << "S = " << s;

    std::cout << "\nmas of " << k << " min elements: ";
    if (k != 0 && k <= n) {
        for (int i = 0; i < k; i++) {
            auto min = *std::min_element(sp1.begin(), sp1.end());
            auto m1 = std::find(sp1.begin(), sp1.end(), min);
            sp1.erase(m1);
            std::cout << " " << min;
        }
    }
}

clock_t generator() {
    return clock();
}

template<typename T>
void printList(const std::list<T>& lst) {
    for (const auto& element : lst) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void task4() {
    std::list<clock_t> clockList(10);
    std::generate(clockList.begin(), clockList.end(), generator);

    std::cout << "first spysok: ";
    printList(clockList);

    clockList.sort();
    clockList.unique();

    std::cout << "spysok without dublicates: ";
    printList(clockList);
}

void task5() {
    std::string str = "Hello, World!";

    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    std::cout << "transform string: " << str << std::endl;
}

template <typename T>
struct Sum {
    T result;

    Sum() : result(0) {}

    void operator()(const T& value) {
        result += value;
    }
};

void task6() {
    std::vector<int> numbers = {};
    int n, a;
    std::cout << "input dimension of vector: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        numbers.push_back(a);
    }


    Sum<int> sum;

    std::for_each(numbers.begin(), numbers.end(), sum);

    std::cout << "sum of elements: " << sum.result << std::endl;
}

void generateAnagrams(std::string& word, int start = 0) {
    if (start == word.length() - 1) {
        std::cout << word << std::endl;
        return;
    }

    for (int i = start; i < word.length(); ++i) {
        std::swap(word[start], word[i]);

        generateAnagrams(word, start + 1);

        std::swap(word[start], word[i]);
    }
}

void task7(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <word>" << std::endl;
    }

    std::string inputWord = argv[1];

    generateAnagrams(inputWord);
}

void generateSentenceAnagrams(const std::vector<std::string>& words, int start = 0) {
    if (start == words.size() - 1) {
        for (const auto& word : words) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (int i = start; i < words.size(); ++i) {
        std::swap(words[start], words[i]);

        generateSentenceAnagrams(words, start + 1);

        std::swap(words[start], words[i]);
    }
}

void task8(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sentence>" << std::endl;
    }

    std::vector<std::string> inputSentence;
    for (int i = 1; i < argc; ++i) {
        inputSentence.push_back(argv[i]);
    }

    generateSentenceAnagrams(inputSentence);

}

struct Point {
    int x1, x2, x3;

    Point() : x1(0), x2(0), x3(0) {}
    Point(int x1, int x2, int x3) : x1(x1), x2(x2), x3(x3) {}
};

double calculateDistance(const Point& p1, const Point& p2) {
    return std::sqrt(std::pow(p2.x1 - p1.x1, 2) + std::pow(p2.x2 - p1.x2, 2) + std::pow(p2.x3 - p1.x3, 2));
}

void task9() {
    std::ifstream inputFile("points.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open file." << std::endl;
    }

    std::vector<Point> points;
    int x1, x2, x3;
    while (inputFile >> x1 >> x2 >> x3) {
        points.push_back(Point(x1, x2, x3));
    }

    std::ofstream outputFile("segments.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to openfile." << std::endl;
    }

    std::vector<std::pair<Point, Point>> segments;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            segments.push_back(std::make_pair(points[i], points[j]));
        }
    }

    std::sort(segments.begin(), segments.end(), [&](const auto& seg1, const auto& seg2) {
        double len1 = calculateDistance(seg1.first, seg1.second);
        double len2 = calculateDistance(seg2.first, seg2.second);
        return len1 < len2;
        });

    for (const auto& segment : segments) {
        outputFile << "(" << segment.first.x1 << "," << segment.first.x2 << "," << segment.first.x3 << ") - "
            << "(" << segment.second.x1 << "," << segment.second.x2 << "," << segment.second.x3 << ")\n";
    }
}

int main() {
    int task;
    std::cout << "task: ";
    std::cin >> task;

    switch (task) {
    case 1: task1(); break;
    case 2: task2(); break;
    case 3: task3(); break;
    case 4: task4(); break;
    case 5: task5(); break;
    case 6: task6(); break;
    case 7: task7(); break;
    case 8:task8(); break;
    case 9:task9(); break;
    }
    return 0;
}