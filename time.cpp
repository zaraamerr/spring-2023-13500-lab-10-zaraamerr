//Zara Amer
//CS 135
//Lab 10

#include <iostream>
#include "time.h"

//write a printer function that prints a Time value on the screen in HOURS:MINUTES format:
void printTime(Time time) {
    std::cout << time.h << ":" << time.m << std::endl;
}

//should return the number of minutes from 0:00AM until time:
int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

//should receive two Time arguments earlier and later and report how many minutes separate the two moments:
int minutesUntil(Time earlier, Time later){
    return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}