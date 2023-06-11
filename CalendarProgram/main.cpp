#include <iostream>
#include "dateType.h"

using namespace std;

int main() {
    dateType baseDate;

    baseDate.printDate();
    cout << baseDate.isLeapYear() << endl;

    dateType date1(3, 15, 2008);

    date1.printDate();
    date1.isLeapYear();

    cout << "Hello World" << endl;

    return 0;
}
