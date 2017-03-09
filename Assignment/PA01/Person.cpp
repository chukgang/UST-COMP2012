//submit this file.
//you must use this exact file name.

#include "Person.h"
#include <iostream>
#include <string>

using namespace std;

//constructor; hint: remember to initialize activityCount to 0 and activities to NULL
	Person::Person(string name) : name(name){
		activityCount = 0;
		activities = NULL;
	}

//destructor;  hint: remember to deallocate any dynamically-allocated memory
	Person::~Person(){
		for(int d = 0; d < activityCount; d++){
			delete []activities[d];
		}
		delete []activities;
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
    		activities = new Activity*[activityCount+1];
    		activities[activityCount] = new Activity(activity.getName(), activity.getTimeslot());
    		activityCount++;
    		return true;
    	}else{
    		for(int i = 0; i < activityCount; i++){
    			if (activities[i]->getName() == activity.getName()){
    				return false;
    			} else if((activities[i]->getTimeslot()).hasConflictsWith(activity.getTimeslot())){
    				return false;
    			} else{
    				continue;
				}
    		}
    		for(int i = 0; i < activityCount; i++){
    		    if ((activities[i]->getTimeslot()).getStartTime() > (activity.getTimeslot()).getStartTime()){
    		    	int startActivityCount = activityCount;
    		    	Activity* before[startActivityCount];
    		    	Activity* after[startActivityCount+1];
					for(int j = 0; j < i; j++){
						before[j] = activities[j];
					}
					for(int k = activityCount; k > i; k--){
						after[k] = activities[k-1];
					}
//					for(int d = 0; d < activityCount; d++){
//						delete []activities[d];
//					}
					delete []activities;
					activities = new Activity*[++activityCount];
					for(int j = 0; j < i; j++){
						activities[j] = before[j];
					}
					activities[i] = new Activity(activity.getName(), activity.getTimeslot());
					for(int k = activityCount-1; k > i; k--){
						activities[k] = after[k];
					}
					delete []before;
					delete []after;
					return true;
    		    }
    		}
    		Activity* backup[activityCount];
			for(int j = 0; j < activityCount; j++){
				backup[j] = activities[j];
			}
//			for(int d = 0; d < activityCount; d++){
//				delete []activities[d];
//			}
			delete []activities;
			activities = new Activity*[++activityCount];
			for(int k = 0; k < activityCount; k++){
				activities[k] = backup[k];
			}
			activities[activityCount-1] = new Activity(activity.getName(), activity.getTimeslot());
			delete []backup;
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
    				Activity* backup[activityCount];
    				for(int j = 0; j < activityCount; j++){
    					backup[j] = activities[j];
					}
//    				for(int d = 0; d < activityCount; d++){
//    					delete []activities[d];
//    				}
    				delete []activities;
    				activities = new Activity*[--activityCount];
    				for(int j = 0, k = 0; j < activityCount; j++, k++){
    					if(j == i){
    						j++;
						}
						activities[k] = backup[j];
    				}
    				delete []backup;
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
    			if (hour>=(activities[i]->getTimeslot()).getStartTime()&&hour<(activities[i]->getTimeslot()).getEndTime()){
    				return false;
    			}
    		}
    		return true;
    	}
    }

////print all the activities for this person; already completed; do not modify
//    void Person::printActivities() const{
//        cout << name  << "'s schedule:" << endl;
//        if(activityCount == 0){
//        	cout << "None." << endl;
//		}else{
//			for(int i=0; i<activityCount; i++){
//				activities[i]->print();
//			}
//        }
//    }
