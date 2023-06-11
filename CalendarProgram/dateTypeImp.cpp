#include <iostream>
#include "dateType.h"

void dateType::setDate(int month, int day, int year) {
    dMonth = month;
    dDay = day;
    dYear = year;
}

int dateType::getDay() const { return dDay; }

int dateType::getMonth() const { return dMonth; }

int dateType::getYear() const { return dYear; }

void dateType::printDate() const {
    std::cout << getMonth() << " / " << getDay() << " / " << getYear() << std::endl;
}

bool dateType::isLeapYear() {
    return dYear % 4 == 0 && (dYear % 100 != 0 || dYear % 400 == 0);
}

dateType::dateType(int month, int day, int year) {
    setDate(month, day, year);
}

