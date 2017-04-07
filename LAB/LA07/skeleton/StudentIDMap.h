#ifndef LAB7_STL_STUDENTIDMAP_H
#define LAB7_STL_STUDENTIDMAP_H

#include <map>
#include <list>
#include <iostream>

using namespace std;

class StudentIDMap {
public:
    StudentIDMap(int nums, string name[], int ID[]);
    bool findStudent(const string&) const;
    int getID(const string&);

    friend ostream& operator<<(ostream& os, const StudentIDMap& studentIDMap);
private:
    map<string, int> nameIDMap;
};


#endif //LAB7_STL_STUDENTIDMAP_H
