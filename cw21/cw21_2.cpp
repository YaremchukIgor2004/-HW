#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

int main() {
    std::vector<std::string> words = { "apple", "banana", "orange", "avocado", "grape", "melon" };

    std::multimap<char, std::string> groupedWords;

    for (const auto& word : words) {
        char key = std::tolower(word.size() > 1 ? word[1] : word[0]);
        groupedWords.insert(std::make_pair(key, word));
    }

    for (const auto& pair : groupedWords) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}