/*
 * Timeslot.cpp
 */

#include "timeslot.h"


 // Initialize the static variable
string Timeslot::weekday_string[] = { "Mon", "Tue", "Wed", "Thu", "Fri" };

// Constructor
Timeslot::Timeslot(weekday d1, weekday d2, int stime, int etime)
        : day1(d1), day2(d2), start(stime), end(etime) { }

// Accessors
bool Timeslot::match(weekday day) const
{
    return (day == day1 || day == day2);
}


bool Timeslot::match(int stime, int etime) const
{
    return (start == stime && end == etime);
}



/* TODO
 * Convert the day in enum type to a printable string
 * using the static string weekday_string[5].
 */
string Timeslot::convert(weekday day) const
{
	//write your codes here
}

/* TODO
 * Please refer to the sample output for output format
 */
ostream& operator<<(ostream& os, const Timeslot& time)
{
	//write your codes here
}


