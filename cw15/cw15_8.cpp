#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {}

    void setTime(int h, int m, int s) {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void displayTime() const {
        std::cout << "Time: " << hours << "h " << minutes << "m " << seconds << "s" << std::endl;
    }

    Time difference(const Time& other) const {
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diffSeconds = std::abs(totalSeconds1 - totalSeconds2);

        int h = diffSeconds / 3600;
        int m = (diffSeconds % 3600) / 60;
        int s = diffSeconds % 60;

        return Time(h, m, s);
    }
};

class Date {
private:
    static bool instanceCreated;
    int year;
    int month;
    int day;

public:
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {
        if (instanceCreated) {
            std::cerr << "Error: Only one instance of Date is allowed." << std::endl;
            exit(1);
        }
        instanceCreated = true;
    }

    void setDate(int y, int m, int d) {
        year = y;
        month = m;
        day = d;
    }

    void displayDate() const {
        std::cout << "Date: " << year << "-" << month << "-" << day << std::endl;
    }
};

bool Date::instanceCreated = false;

int main() {
    Time time1(12, 30, 45);
    Time time2(8, 15, 20);

    time1.displayTime();
    time2.displayTime();

    Time timeDifference = time1.difference(time2);
    std::cout << "Time Difference: ";
    timeDifference.displayTime();

    Date date1(2023, 11, 29);
    date1.displayDate();

    return 0;
}