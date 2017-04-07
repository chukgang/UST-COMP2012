#include <iostream>
#include "StudentList.h"
#include "StudentIDMap.h"
#include "RestaurantQueue.h"

using namespace std;

void checkStudent(const StudentList& slist, const string& name) {
    cout << "Is " << name << " in the list? " << (slist.findStudent(name) ? "Yes" : "No") << endl;
}

void addStudent(StudentList& slist, const string& name) {
    cout << "Add " << name << " into the student list." << endl;
    if(!slist.addStudent(name)) {
        cout << name << " is already in the list." << endl;
    }
}

void removeStudent(StudentList& slist, const string& name) {
    cout << "Remove " << name << " from the student list." << endl;
    if(!slist.deleteStudent(name)) {
        cout << name << " is not in the list." << endl;
    }
}

int main() {
    cout << "************************** Part1: list - New Students Registration **************************" << endl;
    string studentName[] = {"Allen", "Bob", "Cindy", "Drake", "Emily", "Fiona", "Gary"};

    StudentList studentList(7, studentName);
    cout << "student list: " << studentList << endl;
    checkStudent(studentList, studentName[3]);
    checkStudent(studentList, "Hannah");
    cout << endl;

    addStudent(studentList, studentName[3]);
    addStudent(studentList, "Hannah");
    cout << "student list: " << studentList << endl;
    cout << endl;


    removeStudent(studentList, "Ivan");
    removeStudent(studentList, studentName[3]);
    cout << "student list" << studentList << endl;
    cout << endl << endl;

    cout << "************************* Part2: map - Student ID **************************" << endl;
    int ID[] = {0, 1, 2, 32, 64, 65536, 2147483647};
    StudentIDMap studentIDMap(7, studentName, ID);
    cout << "student name-ID map: " << studentIDMap << endl;
    cout << "Is " << studentName[4] << " in the map? " << (studentIDMap.findStudent(studentName[4]) ? "Yes" : "No") << endl;
    cout << studentName[4] << "'s ID is " << studentIDMap.getID(studentName[4]) << endl;
    cout << "Is Jack in the map? " << (studentIDMap.findStudent("Jack") ? "Yes" : "No") << endl;
    cout << endl << endl;

    cout << "************************** Part3: queue - Restaurant Waiting Queue **************************" << endl;
    RestaurantQueue restaurantQueue;
    restaurantQueue.serveStudent();
    for(int i=0; i < 3; i++)
        restaurantQueue.addStudent(studentName[i]);
    cout << "current number of waiting people in the restaurant: " << restaurantQueue.waitNum() << endl;
    cout << endl;

    for(int i=0; i < 2; i++) {
        restaurantQueue.serveStudent();
        cout << "current number of waiting people in the restaurant: " << restaurantQueue.waitNum() << endl << endl;
    }

    restaurantQueue.addStudent(studentName[5]);
    restaurantQueue.serveStudent();
    restaurantQueue.serveStudent();
    restaurantQueue.serveStudent();

    return 0;

}
