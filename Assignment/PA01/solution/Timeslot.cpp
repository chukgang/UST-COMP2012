//submit this file.
//you must use this exact file name.

#include "Timeslot.h"

Timeslot::Timeslot(int startTime, int endTime) : startTime(startTime), endTime(endTime) //constructor
{
}

bool Timeslot::hasConflictsWith(const Timeslot& another) const
{
	return !( endTime <= another.startTime || another.endTime <= startTime );
}

int Timeslot::getStartTime() const //return the start time
{
	return startTime;
}

int Timeslot::getEndTime() const //return the end time
{
	return endTime;
}
