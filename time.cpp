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
std::string getTimeSlot(TimeSlot ts){
    std::string mt;
	Movie movie = ts.movie;
	Time start = ts.startTime;
	std::string sTime = std::to_string(start.h) + ":" + std::to_string(start.m);
	Time end = addMinutes(ts.startTime, movie.duration);
	std::string eTime = std::to_string(end.h) + ":" + std::to_string(end.m);

	std::string g;
	switch(movie.genre) {
		case ACTION : g = "ACTION"; break;
		case COMEDY : g = "COMEDY"; break;
        case DRAMA : g = "DRAMA"; break;
		case ROMANCE : g = "ROMANCE"; break;
		case THRILLER : g = "THRILLER"; break;	
	}
	mt = movie.title + " " + g + " (" + std::to_string(movie.duration) + " min) [starts at " + sTime + ", ends by " + eTime + "]";
	return mt;
}

//task d
//should produce and return a new TimeSlot for the movie 'nextMovie', scheduled immediately after the time slot 'ts'
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot nextSlot;
    nextSlot.movie = nextMovie;
    nextSlot.startTime = addMinutes(ts.startTime, ts.movie.duration);
    return nextSlot;
}

//task e
//should return true if the two time slots overlap, otherwise return false. 
//(Take into account the starting times of the time slots and the duration of the scheduled movies.)
/*Hint: You may use minutesUntil to check which time slot is earlier, then find the how long is the interval between their starting
times. They overlap if the movie duration is greater than the interval between the time slots’ starting times. Alternatively, 
converting times into minutes since midnight can be a good idea as well. (By the way, if you want to be accurate, if one movie starts
at 10:00 and lasts 90 minutes until 11:30, then it does not overlap with a movie that starts exactly at 11:30. However, they would 
overlap if the latter movie started one minute earlier, at 11:29.)*/
bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
     if(minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)) {
        return ts1.movie.duration > (minutesSinceMidnight(ts2.startTime) - minutesSinceMidnight(ts1.startTime));
    } else {
        return ts2.movie.duration > (minutesSinceMidnight(ts1.startTime) - minutesSinceMidnight(ts2.startTime));
    }
}


