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
    std::cout << getMonth() << "-" << getDay() << "-" << getYear();
}

bool dateType::isLeapYear() {
    return dYear % 4 == 0 && (dYear % 100 != 0 || dYear % 400 == 0);
}

dateType::dateType(int month, int day, int year) {
    setDate(1, 1, year);
    // bool currentlyLeapYear = dateType::isLeapYear();

    if(month <= 0 || month >= 13) {
        month = 1;
    }

    if(day <= 0 || day >= 32) {
        day = 1;
    }
    
    if(month == 2) {
        if(day <= 28 || (day == 29 && isLeapYear())) {
            setDate(month, day, year);
        } else {
          day = 1;
        }
    } else {
        if((month == 4 || month == 6 || month == 10) && day == 31) {
            day = 1;
        }
    }

    setDate(month, day, year);
}

