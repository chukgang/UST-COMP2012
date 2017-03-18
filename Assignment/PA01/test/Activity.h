//do NOT submit this file.
//do NOT modify this file.

#include <iostream>
#include <string>
#include "Timeslot.h"

using namespace std;

class Activity
{
public:

	//*** destructor and static variable added for testing ***
	static int destructionCount; //just consider that as some kind of global variable - you will learn about that later in COMP2012
								 //destructionCount will keep track of, in total, how many times the Activity objects are properly destructed (i.e. Activity destructor called)
    ~Activity()
    {
    	destructionCount++; //add 1 to the destructionCount whenever the destructor is called
    }

    Activity(string name, const Timeslot& timeslot); //constructor
    string getName() const; //return the acitivity's name
	const Timeslot& getTimeslot() const; //return the acitivity's timeslot

    void print() const //print the name and timeslot of the activity; already completed; do not modify
    {
        timeslot.print();
        cout << " " << name;
    }

private:
    string name; //the string that stores the activity's name
    Timeslot timeslot; //the timeslot object which stores the start time and end time for this activity
};
