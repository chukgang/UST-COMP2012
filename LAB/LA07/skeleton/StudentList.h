#ifndef LAB7_STL_STUDENTLIST_H
#define LAB7_STL_STUDENTLIST_H

#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

class StudentList {
public:
    StudentList(int num, string nameList[]);

    bool findStudent(const string& name) const{
    	return find(nameList.begin(), nameList.end(), name);
    };

    bool addStudent(const string& name){
    	if(findStudent(name) == true){
    		return false;
    	} else{
    		nameList.push_back(name);
    		return true;
    	}
    };

    bool deleteStudent(const string& name){
    	if(findStudent(name) == true){
    		iterator itr = nameList.begin();
    		for(int i = 0; i < nameList.size(); i++, itr++){
    			if(nameList[i] == name){
    				nameList.erase (itr);
    			}
    		}
    		return true;
    	} else{
    		return false;
    	}
    };

    friend ostream& operator<<(ostream& os, const StudentList& studentList);

private:
    list<string> nameList;

};


#endif //LAB7_STL_STUDENTLIST_H
