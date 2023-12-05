#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// Lab 10 Task 3

typedef struct {
    uint16_t year;
    uint16_t month;
    uint16_t day;
} Date;

bool is_leap_year(uint16_t y) {
    return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

uint16_t days_in_month(uint16_t m, bool is_leap) {
    const uint16_t d[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    return d[m] + (uint16_t)(is_leap && m == 1);
}

Date next_day(Date date) {
    date.day += 1;
    bool is_leap = is_leap_year(date.year);
    uint16_t d = days_in_month(date.month, is_leap);
    if (date.day < d) return date;
    date.day -= d;
    date.month += 1;
    if (date.month < 12) return date;
    date.month -= 12;
    date.year += 1;
    return date;
}

int main(void) {
    // today date: 26.10.23
    const Date today = (Date){
        .day = 25,
        .month = 9,
        .year = 2022,
    };

    const Date tomorrow = next_day(today);
    printf("%02hu.%02hu.%04hu", tomorrow.day + 1, tomorrow.month + 1, tomorrow.year + 1);
}