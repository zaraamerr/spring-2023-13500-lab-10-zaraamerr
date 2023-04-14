#pragma once

//Copy the class Time declaration in your program, it should be placed before main() function
class Time { 
public:
    int h;
    int m;
};

void printTime(Time time);
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
Time addMinutes(Time time0, int min);