#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>

struct Date {
    int day, month, year;
};

Date parseDate(const std::string& dateString) {
    Date date;
    char discard;
    std::istringstream ss(dateString);

    ss >> discard >> date.day >> discard >> date.month >> discard >> date.year >> discard;

    return date;
}

void findMinMaxDates(const std::vector<Date>& dates, Date& oldestDate, Date& newestDate) {
    oldestDate = newestDate = dates.front();

    for (const Date& date : dates) {
        if (date.year < oldestDate.year || (date.year == oldestDate.year && date.month < oldestDate.month) ||
            (date.year == oldestDate.year && date.month == oldestDate.month && date.day < oldestDate.day)) {
            oldestDate = date;
        }

        if (date.year > newestDate.year || (date.year == newestDate.year && date.month > newestDate.month) ||
            (date.year == newestDate.year && date.month == newestDate.month && date.day > newestDate.day)) {
            newestDate = date;
        }
    }
}

int main() {
    std::ifstream inputFile("dates.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    std::vector<Date> dates;
    std::string dateString;

    while (std::getline(inputFile, dateString)) {
        dates.push_back(parseDate(dateString));
    }

    inputFile.close();

    if (dates.empty()) {
        std::cerr << "No dates found in the input file." << std::endl;
        return 1;
    }

    Date oldestDate, newestDate;
    findMinMaxDates(dates, oldestDate, newestDate);

    std::ofstream outputFile("result.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Unable to open output file." << std::endl;
        return 1;
    }

    outputFile << "Oldest Date: " << std::setfill('0') << std::setw(2) << oldestDate.day << "/"
        << std::setw(2) << oldestDate.month << "/" << std::setw(4) << oldestDate.year << std::endl;

    outputFile << "Newest Date: " << std::setfill('0') << std::setw(2) << newestDate.day << "/"
        << std::setw(2) << newestDate.month << "/" << std::setw(4) << newestDate.year << std::endl;

    outputFile.close();

    std::cout << "Operation completed successfully." << std::endl;

    return 0;
}
