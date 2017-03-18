//submit this file.
//you must use this exact file name.

#include "TimeManager.h"

TimeManager::TimeManager() : persons(NULL), personCount(0)
{
}

TimeManager::~TimeManager()
{
	for(int i=0; i<personCount; i++)
	{
		delete persons[i];
	}
	delete [] persons;
}

bool TimeManager::addPerson(string name) 
{
	//return false if the name already exists
	if(doesPersonExist(name))
		return false;

	//now add the person
	Person* newPerson = new Person(name);
	Person** newPersons = new Person*[++personCount];
	for(int i=0; i<personCount-1; i++)
		newPersons[i] = persons[i];
	newPersons[personCount-1] = newPerson;
	delete [] persons;
	persons = newPersons;
	return true;
}

bool TimeManager::addActivityForPerson(string personName, const Activity& activity)
{
	for(int i=0; i<personCount; i++)
	{
		if(persons[i]->getName() == personName)
		{
			return persons[i]->addActivity(activity);
		}
	}
	return false; //name is not found
}

bool TimeManager::removePerson(string name) 
{
	for(int i=0; i<personCount; i++)
	{
		if(persons[i]->getName() == name) //found the name
		{
			//remove it
			Person** newPersons = new Person*[personCount-1];
			for(int j=0;j<personCount;j++)
			{
				if(j < i) newPersons[j] = persons[j];
				else if(j > i) newPersons[j - 1] = persons[j];
				else if(j == i)
				{
					delete persons[j];
				}
			}
			personCount--;
			delete [] persons;
			persons = newPersons;
			return true;
		}
	}
	return false; //name is not found
}

bool TimeManager::removeActivityForPerson(string personName, string activityName)
{
	for(int i=0; i<personCount; i++)
	{
		if(persons[i]->getName() == personName) //found the name
		{
			return persons[i]->removeActivity(activityName);
		}
	}
	return false; //name is not found
}

bool TimeManager::doesPersonExist(string name) const
{
	for(int i=0; i<personCount; i++)
	{
		if(persons[i]->getName() == name)
		{
			return true;
		}
	}
	return false; //name is not found
}

Timeslot* TimeManager::findFirstCommonTimeslot() const
{
	int freeTimeslotStartTime = -1;
	int freeTimeslotEndTime = -1;
	for(int i=0; i<=24; i++)
	{
		bool isThisHourGood = true;
		if (i==24)
			isThisHourGood=false;
		else
			for(int j=0; j<personCount; j++)
			{
				if(!persons[j]->isFreeAtHour(i))
					isThisHourGood = false;
			}
		if(isThisHourGood)
		{
			if(freeTimeslotStartTime == -1)
				freeTimeslotStartTime = i;
			freeTimeslotEndTime = i+1;
		}
		else
		{
			if(freeTimeslotStartTime != -1) //got a good timeslot already?
			{
				return new Timeslot(freeTimeslotStartTime, freeTimeslotEndTime);
			}
		}
	}

	return NULL;
}

void TimeManager::findAllCommonTimeslots(Timeslot**& results, int& timeslotCount) const
{
	results = NULL;
	timeslotCount = 0;

	int freeTimeslotStartTime = -1;
	int freeTimeslotEndTime = -1;
	for(int i=0; i<=24; i++)
	{
		bool isThisHourGood = true;
		if (i==24)
			isThisHourGood=false;
		else
			for(int j=0; j<personCount; j++)
			{
				if(!persons[j]->isFreeAtHour(i))
					isThisHourGood = false;
			}
		if(isThisHourGood)
		{
			if(freeTimeslotStartTime == -1)
				freeTimeslotStartTime = i;
			freeTimeslotEndTime = i+1;
		}
		else
		{
			if(freeTimeslotStartTime != -1) //got a good timeslot already?
			{
				//add one to the results
				timeslotCount++;
				Timeslot** newResults = new Timeslot*[timeslotCount];
				for(int k=0; k<timeslotCount-1; k++)
				{
					newResults[k] = results[k];
				}
				newResults[timeslotCount-1] = new Timeslot(freeTimeslotStartTime, freeTimeslotEndTime);
				delete [] results;
				results = newResults;
				freeTimeslotStartTime = -1;
				freeTimeslotEndTime = -1;
			}
		}
	}
}
