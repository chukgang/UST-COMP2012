//submit this file.
//you must use this exact file name.

#include "Person.h"

Person::Person(string name) : name(name), activities(NULL), activityCount(0)
{
}

Person::~Person()
{
	for(int i=0; i<activityCount; i++)
	{
		delete activities[i];
	}
	delete [] activities;
}

string Person::getName() const
{
	return name;
}

bool Person::addActivity(const Activity& activity)
{
	//return false if the activity name already exists
	for(int i=0; i<activityCount; i++)
	{
		if(activities[i]->getName() == activity.getName())
		{
			return false;
		}
	}

	//check if there is any time conflict
	for(int i=0; i<activityCount; i++)
	{
		if( activity.getTimeslot().hasConflictsWith(activities[i]->getTimeslot()) )
		{
			//time conflict, return false
			return false;
		}
	}

	//find the insert location
	int newActivityIndex = -1;
	int i=0;
	if(activityCount == 0)
		newActivityIndex = 0;
	else{   //find an activity with a start time bigger than or equal to the end time of the current activity we are adding
			//must put the check i<activityCount as the 1st condition, otherwise it will check array[i], where i could already be too big
			while(i<activityCount && activity.getTimeslot().getEndTime() > activities[i]->getTimeslot().getStartTime())
			{
				i++;
			}
	}
	newActivityIndex=i;

	//insert the new activity to the location found
	Activity** newActivities = new Activity*[++activityCount];
	Activity* newActivity = new Activity(activity);
	newActivities[newActivityIndex] = newActivity;

	//copy over the existing activities
	for(int i=0; i<activityCount-1; i++)
	{
		newActivities[i>=newActivityIndex?(i+1):i] = activities[i];
	}

	//clean up and update the pointer
	delete [] activities;
	activities = newActivities;

    return true;
}

bool Person::removeActivity(string activityName)
{
	for(int i=0; i<activityCount; i++)
	{
		if(activities[i]->getName() == activityName) //found it
		{
			//remove it
			Activity** newActivities = new Activity*[activityCount-1];
			for(int j=0;j<activityCount;j++)
			{
				if(j < i) newActivities[j] = activities[j];
				else if(j > i) newActivities[j - 1] = activities[j];
				else if(j == i)
				{
					delete activities[j];
				}
			}
			activityCount--;
			delete [] activities;
			activities = newActivities;
			return true;
		}
	}

	return false; //activity is not found
}

bool Person::isFreeAtHour(int hour) const
{
	for(int i=0; i<activityCount; i++)
	{
//		if(activities[i]->getTimeslot().getStartTime() <= hour && hour < activities[i]->getTimeslot().getEndTime()) //more efficient
		if(activities[i]->getTimeslot().hasConflictsWith(Timeslot(hour, hour+1))) //easier
			return false; //hour in timeslot, return false
	}
	return true;
}
