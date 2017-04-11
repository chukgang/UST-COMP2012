#ifndef LAB7_STL_STUDENTLIST_H
#define LAB7_STL_STUDENTLIST_H

#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

class StudentList {
public:
    StudentList(int num, string nameList[]): nameList(num){
    	list<string>::iterator itr;
    	itr = this->nameList.begin();
    	for(int i = 0; i < num; i++, itr++){
    		*itr = nameList[i];
    	}
    };

    bool findStudent(const string& name) const{
    	if(find(nameList.begin(), nameList.end(), name) != nameList.end()){
    		return true;
    	}else{
    		return false;
    	}
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
    	list<string>::iterator itr;
    	itr = find(nameList.begin(), nameList.end(), name);
    	if(itr != nameList.end()){
    		nameList.erase (itr);
    		return true;
    	}else{
    		return false;
    	}
    };

    friend ostream& operator<<(ostream& os, const StudentList& studentList){
    	list<string>::const_iterator itr = studentList.nameList.begin();
    	os << "[" << *itr;
    	itr++;
    	for(; itr != studentList.nameList.end(); itr++){
    		os << ", " << *itr;
    	}
    	os << "]";
    	return os;
    };

private:
    list<string> nameList;

};

#endif //LAB7_STL_STUDENTLIST_H
