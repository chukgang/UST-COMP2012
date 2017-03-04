//submit this file.
//you must use this exact file name.

#include "TimeManager.h"
#include "Person.h"

//constructor; hint: remember to initialize personCount to 0 and persons to NULL
    TimeManager::TimeManager(){
    	persons = NULL;
    	personCount = 0;
    }

//destructor; hint: remember to deallocate any dynamically-allocated memory
    TimeManager::~TimeManager(){
    	delete []persons;
    }

/*
 * add a person and return true if the person can be added successfully
 * do nothing and return false otherwise - that means the person name already exists (i.e. same as one of the existing persons')
 */
    bool TimeManager::addPerson(string name){
    	if(personCount == 0){
    		persons = new Person*[personCount+1];
    		persons[personCount] = new Person(name);
    		personCount++;
    		return true;
    	}else{
    		for(int i = 0; i < personCount; i++){
    			if(name == persons[i]->getName()){
    				return false;
    			}
    		}
    		Person* backup[personCount];
    		for(int j = 0; j < personCount; j++){
    			backup[j] = persons[j];
    		}
    		delete []persons;
    		persons = new Person*[++personCount];
    		for(int k = 0; k < personCount; k++){
    			persons[k] = backup[k];
    		}
    		persons[personCount-1] = new Person(name);
    		return true;
    	}
    }

/*
 * add an activity for the specified person and return true if it can be done successfully
 * do nothing and return false otherwise - that means either
 * (1) the person cannot be found by the given name
 * (2) calling the function addActivity on the found person object returns false (which signals that it cannot be done for some reason)
 */
    bool TimeManager::addActivityForPerson(string personName, const Activity& activity){
    	if(personCount == 0){
    		return false;
    	}
    	for(int i = 0; i < personCount; i++){
    		if(personName == persons[i]->getName()){
    			return persons[i]->addActivity(activity);
    		}
    	}
    	return false;
    }

/*
 * remove the specified person and return true if it can be done successfully
 * do nothing and return false if it cannot be done - which means the person cannot be found by the given name
 */
    bool TimeManager::removePerson(string name){
    	if(personCount == 0){
    		return false;
    	}else{
    		for(int i = 0; i < personCount; i++){
    			if(name == persons[i]->getName()){
    	    		Person* backup[personCount];
    	    		for(int j = 0; j < personCount; j++){
    	    			backup[j] = persons[j];
    	    		}
    	    		delete []persons;
    	    		persons = new Person*[--personCount];
    	    		for(int j = 0, k = 0; j < personCount + 1; j++, k++){
    	    			if(j == i){
    	    				j++;
    	    			}
        	    		persons[k] = backup[j];        	    		
    	    		}
    	    		return true;
    			}
    		}
    		return false;
    	}
    }

/*
 * remove the specified activity for the specified person and return true if it can be done successfully
 * do nothing and return false if it cannot be done - that means either
 * (1) the person cannot be found by the given name
 * (2) calling the function removeActivity on the found person object returns false (which signals that it cannot be done for some reason)
 */
    bool TimeManager::removeActivityForPerson(string personName, string activityName){
    	if(doesPersonExist(personName)){
    		for(int i = 0; i < personCount; i++){
    			if(personName == persons[i]->getName()){
					return persons[i]->removeActivity(activityName);
				}
			}
		}
		return false;
    }

/*
 * return true if a person with the given name exists already
 * return false otherwise
 */
    bool TimeManager::doesPersonExist(string name) const{
    	if(personCount == 0){
    		return false;
		} else{
			for(int i = 0; i < personCount; i++){
				if(name == persons[i]->getName()){
					return true;
				}
			}
			return false;
		}    	
    }

/*
 * find the first (i.e. earliest) common timeslot for all persons
 * read the webpage description for detailed specification and examples
 * a new timeslot object should be created and returned to represent the result
 * simply return NULL if no common timeslot is found
 * you can assume there is at least one person added when this function is called
 */
    Timeslot* TimeManager::findFirstCommonTimeslot() const{
    	if(personCount == 0){
    		return NULL;
		}
		bool freeCommonTimeslot[24];
		int startTime = 24, endTime = 24;
		for(int i = 0; i < 24; i++){
			freeCommonTimeslot[i] = true;
		}
		for(int j = 0; j < personCount; j++){
			for(int k = 0; k < 24; k++){
				if(freeCommonTimeslot[k] == true){
					freeCommonTimeslot[k] = persons[j]->isFreeAtHour(k);
				}else{
					continue;
				}
			}
		}
		int l, m;
		for(l = 0; l < 24; l++){
			if(freeCommonTimeslot[l] == true){
				startTime = l;
				break;
			}
		}
		if(startTime == 24){
			return NULL;
		}
		for(m = l + 1; m < 24; m++){
			if(freeCommonTimeslot[m] == false){
				endTime = m;
				break;
			}
		}
		Timeslot* firstCommonTimeslot = new Timeslot(startTime, endTime);
		return firstCommonTimeslot;
    }

/*
 * find all the common timeslots for all persons
 * read the webpage description for detailed specification and examples
 * a dynamic timeslot array, which stores all the common timeslots, should be created and returned via "results" which is a passed-by-reference parameter
 * similarly, the number of elements in the said array should also be returned via "timeslotCount" which is also a passed-by-reference parameter
 * "results" should be set to NULL and "timeslotCount" should be set to 0 if no common timeslot is found
 * you can assume there is at least one person added when this function is called
 */
    void TimeManager::findAllCommonTimeslots(Timeslot**& results, int& timeslotCount) const{
		if(findFirstCommonTimeslot() == NULL){
			results = NULL;
			timeslotCount = 0;
		}else{
			bool freeCommonTimeslot[24];
			int startTime = 24, endTime = 24;
			bool startChanged = false, endChanged = false;
			for(int i = 0; i < 24; i++){
				freeCommonTimeslot[i] = true;
			}
			for(int j = 0; j < personCount; j++){
				for(int k = 0; k < 24; k++){
					if(freeCommonTimeslot[k] == true){
						freeCommonTimeslot[k] = persons[j]->isFreeAtHour(k);
					}else{
						continue;
					}
				}
			}
			timeslotCount = 0;
			for(int l = 0; l < 23; l++){
				if(freeCommonTimeslot[l] == 1&&freeCommonTimeslot[l+1] == 0){
					timeslotCount++;
				}
				if(l == 22&&freeCommonTimeslot[23] == 1){
					timeslotCount++;
				}
			}
			cout << timeslotCount;
			results = new Timeslot*[timeslotCount];
			int currentTime = 0;
			for(int m = 0; m < timeslotCount; m++){
				int startTime, endTime;
				for(startTime = currentTime; startTime < 24; startTime++){
					if(freeCommonTimeslot[startTime] == true){
						break;
					}
				}
				for(endTime = startTime + 1; endTime < 24; endTime++){
					if(freeCommonTimeslot[endTime] == false){
						currentTime = endTime;
						break;
					}
				}
				results[m] = new Timeslot(startTime, endTime);				
			}
		}
    }

//    void print() const //print the schedule of all persons one by one; already completed; do not modify
//    {
//    	if(personCount == 0) cout << "There is nothing in the database yet." << endl;
//    	else
//    	{
//    		cout << "Listing schedule of all " << personCount << " "<< (personCount>1?"persons":"person") << "..." << endl;
//    		for(int i=0; i<personCount; i++)
//    		{
//    			persons[i]->printActivities();
//    		}
//    	}
//    }

//private:
//    Person** persons; //the dynamic array, which is just big enough, that stores all the persons in the system; it should be NULL at the beginning
//    int personCount; //the number of persons; it should be 0 at the beginning

