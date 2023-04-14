#include <iostream>
#include "time.h"

int main() {
    Time time1;
    time1.h = 10;
    time1.m = 30;
    printTime(time1); //should print 10:30
    std::cout << minutesSinceMidnight(time1) << std::endl; //should print 630
    Time time2;
    time2.h = 13;
    time2.m = 40;
    std::cout << minutesUntil(time1, time2) << std::endl; //should print 190
    //A caveat: If the earlier moment of time happens to be after the later moment of time, report a negative number of minutes.
    std::cout << minutesUntil(time2, time1) << std::endl; //should print -190
    //test addMinutes
    Time time3 = addMinutes(time1, 190); //add 190 to 10:30
    printTime(time3); //should print 13:40
    return 0;
}
