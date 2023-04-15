//Zara Amer
//CS 135
//Lab 10

#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

//write a printer function that prints a Time value on the screen in HOURS:MINUTES format:
void printTime(Time time) {
    std::cout << time.h << ":" << time.m << std::endl;
}

//should return the number of minutes from 0:00AM (midnight) until time:
int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

//should receive two Time arguments 'earlier' and 'later' and report how many minutes separate the two moments:
int minutesUntil(Time earlier, Time later){
    return (later.h - earlier.h) * 60 + (later.m - earlier.m);
}

//task B
//should create and return a new moment of time that is 'min' minutes after 'time0'.
Time addMinutes(Time time0, int min){
    time0.h += min / 60;
    time0.m += min % 60;
    if (time0.m >= 60) {
        time0.h += time0.m / 60;
        time0.m %= 60;
    }
    return time0;
}

void printMovie(Movie mv){
    std::string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

//task c
void printTimeSlot(TimeSlot ts){
   Time endTime = addMinutes(ts.startTime, ts.movie.duration);
   printMovie(ts.movie);
   std::cout << " [starts at " << ts.startTime.h << ":" << ts.startTime.m 
              << ", ends by " << endTime.h << ":" << endTime.m << "]" << "\n";
}

//task d
//should produce and return a new TimeSlot for the movie 'nextMovie', scheduled immediately after the time slot 'ts'
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot nextSlot;
    nextSlot.movie = nextMovie;
    nextSlot.startTime = addMinutes(ts.startTime, ts.movie.duration);
    return nextSlot;
}