#include <iostream>
#include "time.h"
#include "movie.h"
#include "timeslot.h"

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
    //test Movie and TimeSlot
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, Time{9, 15}};  
    TimeSlot daytime = {movie2, Time{12, 15}}; 
    TimeSlot evening = {movie2, Time{16, 45}}; 
    printTimeSlot(morning); //should print Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]
    printTimeSlot(daytime); //should print Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]
    printTimeSlot(evening); //should print Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]

    return 0;
}
