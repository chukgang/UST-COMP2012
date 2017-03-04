//submit this file.
//you must use this exact file name.

#include "Timeslot.h"
#include <iostream>
using namespace std;

//constructor
    Timeslot::Timeslot(int startTime, int endTime) : startTime(startTime), endTime(endTime){
    }

//return true if there is a time conflict with another timeslot
//return false otherwise
//e.g. [03:00-05:00] conflicts with [04:00-06:00] and [02:00-06:00], but not [05:00-06:00]
    bool Timeslot::hasConflictsWith(const Timeslot& another) const{
    	if(((this->getStartTime()<another.getEndTime())&&(this->getStartTime()>=another.getStartTime()))||((this->getEndTime()>another.getStartTime())&&(this->getEndTime()<=another.getEndTime()))){
    		return true;
    	}else{
    		return false;
    	}
    }

//return the start time
    int Timeslot::getStartTime() const{
    	return startTime;
    }

//return the end time
    int Timeslot::getEndTime() const{
    	return endTime;
    }

////a helper function to format and print the hour; already completed; do not modify
//    void Timeslot::printHour(int hour) const
//    {
//        cout << (hour<=9?"0":"") << hour << ":00";
//    }
//
////print the timeslot information; already completed; do not modify
//    void Timeslot::print() const
//    {
//    	cout << "[";
//        printHour(startTime);
//        cout << "-";
//        printHour(endTime);
//        cout << "]";
//    }
