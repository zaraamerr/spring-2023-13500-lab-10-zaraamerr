#pragma once

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printTimeSlot(TimeSlot ts);