//submit this file.
//you must use this exact file name.


#include <iostream>
#include <string>
#include "Timeslot.h"
#include "Activity.h"

using namespace std;


//constructor
    Activity::Activity(string name, const Timeslot& timeslot) : name(name), timeslot(timeslot){
    }

//return the acitivity's name
    string Activity::getName() const{
    	return name;
    }

//return the acitivity's timeslot
    const Timeslot& Activity::getTimeslot() const{
    	return timeslot;
    }

////print the name and timeslot of the activity; already completed; do not modify
//    void Activity::print() const{
//            timeslot.print();
//            cout << " " << name << endl;
//    }
