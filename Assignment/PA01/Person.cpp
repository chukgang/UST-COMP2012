//submit this file.
//you must use this exact file name.

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

//constructor; hint: remember to initialize activityCount to 0 and activities to NULL
	Person::Person(string name){
		this->name = name;
		activityCount = 0;
		activities = NULL;
	}

//destructor;  hint: remember to deallocate any dynamically-allocated memory
	Person::~Person(){
		delete activities;
	}

//return the person's name
	string Person::getName() const{
		return name;
	}

/*
 * add an activity
 * return true if the activity can be added successfully
 * do nothing and return false otherwise - that means either:
 * (1) the activity name already exists (i.e. same as one of the existing activities') for this person
 * (2) there is some time conflict between the new activity and one of the existing activities for this person
 * note: it is required that you make sure the activities are always stored in a sorted order (by time, as you can observe in the printed activities in the examples)
 * therefore, as you insert a new activity, find a proper location in the array to do so, so that the activities are always sorted by time
 */
    bool Person::addActivity(const Activity& activity){
    	if(activityCount == 0){
    		activityCount++;
    		activities = activity;
    		return true;
    	}else{
    		for(int i = 0; i < activityCount; i++){
    			if (activities[i]->getName() == activity.getName()){
    				return false;
    			} else if((activities[i]->getTimeslot()).hasConflictsWith(activity.getTimeslot())){
    				return false;
    			}
    		}
    		for(int i = 0; i < activityCount; i++){
    		    if ((activities[i]->getTimeslot()).getStartTime() > (activity.getTimeslot()).getStartTime()){
    		    	activityCount++;
    		    	activities[i+1] = activities[i];
    		    	activities[i] = activity;
    		    	return true;
    		    }
    		}
    		activities[activityCount] = activity;
    		activityCount++;
    		return true;
    	}
    }

/*
 * remove the specified activity and return true if it can be done successfully
 * do nothing and return false if it cannot be done - which means the activity cannot be found by the given name
 */
    bool Person::removeActivity(string activityName){
    	if(activityCount == 0){
    		return false;
    	}else{
    		for(int i = 0; i < activityCount; i++){
    			if(activities[i]->getName() == activityName){
    				delete activities[i];
    				activityCount--;
    				for(int j = i; j < activityCount; j++){
    					activities[j] = activities[j+1];
    				}
    				delete activities[activityCount-1];
    				return true;
    			}
    		}
    		return false;
    	}
    }

/*
 *  return true if the person is free at the hour specified
 *  return false otherwise
 *
 *  For example, if the person currently has only two activities:
 *  [02:00-04:00] Activity One
 *  [05:00-06:00] Activity Two
 *
 *  then,
 *  isFreeAtHour(0) should return true;
 *  isFreeAtHour(1) should return true;
 *  isFreeAtHour(2) should return false;
 *  isFreeAtHour(3) should return false;
 *  isFreeAtHour(4) should return true;
 *  isFreeAtHour(5) should return false;
 */
    bool Person::isFreeAtHour(int hour) const{
    	if(activityCount == 0){
    		return true;
    	}else{
    		for(int i = 0; i < activityCount; i++){
    			if (hour>(activities[i]->getTimeslot()).getStartTime()&&hour<(activities[i]->getTimeslot()).getEndTime()){
    				return false;
    			}
    		}
    		return true;
    	}
    }

//print all the activities for this person; already completed; do not modify
    void Person::printActivities() const
    {
        cout << name  << "'s schedule:" << endl;
        if(activityCount == 0)
        	cout << "None." << endl;
        else
        {
			for(int i=0; i<activityCount; i++)
			{
				activities[i]->print();
			}
        }
    }
