#include "Date.h"


Date::Date(int month, int day, int year) {
    setMonth(month);
    setDay(day);
    setYear(year);
}


void Date::setMonth(int month) {
    if (month >= 1 and month <= 12)
        this->month = month;
    else 
        this->month = 1;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setYear(int year) {
    this->year = year;
}

int Date::getMonth() const {
    return month;
}

int Date::getDay() const {
    return day;
}

int Date::getYear() const {
    return year;
}

void Date::displayDate() const {
    cout << month << "/" << day << "/" << year << endl;
}
