#include <iostream>
#include "time.h"

int main() {
    Time time1;
    time1.h = 10;
    time1.m = 30;
    printTime(time1);
    std::cout << minutesSinceMidnight(time1) << std::endl;
    Time time2;
    time2.h = 13;
    time2.m = 40;
    std::cout << minutesUntil(time1, time2) << std::endl;
    return 0;
}
