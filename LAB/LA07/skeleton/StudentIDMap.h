#ifndef LAB7_STL_STUDENTIDMAP_H
#define LAB7_STL_STUDENTIDMAP_H

#include <map>
#include <list>
#include <iostream>
#include "StudentList.h"
#include <iterator>
#include <algorithm>

using namespace std;

class StudentIDMap {
public:
    StudentIDMap(int nums, string name[], int ID[]){
    	for(int i = 0; i < nums; i++){
    		nameIDMap.insert(pair<string, int>(name[i], ID[i]));
    	}
    };

    bool findStudent(const string& name) const{
    	if(nameIDMap.find(name) != nameIDMap.end()){
    		return true;
    	}else{
    		return false;
    	}
    };

    int getID(const string& name){
        	return nameIDMap[name];
    };

    friend ostream& operator<<(ostream& os, const StudentIDMap& studentIDMap){
    	map<string, int>::const_iterator itr = studentIDMap.nameIDMap.begin();
    	os << "{(" << itr->first <<  ", " << itr->second;
    	itr++;
    	for(; itr != studentIDMap.nameIDMap.end(); itr++){
    		os << ", " << "(" << itr->first <<  ", " << itr->second << ")";
    	}
    	os<< "}";
    	return os;
    };

private:
    map<string, int> nameIDMap;
};


#endif //LAB7_STL_STUDENTIDMAP_H
