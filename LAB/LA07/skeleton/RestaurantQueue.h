#ifndef LAB7_STL_RESTAURANTQUEUE_H
#define LAB7_STL_RESTAURANTQUEUE_H
#include <queue>
#include <iostream>

using namespace std;

class RestaurantQueue {
public:
    void serveStudent();
    void addStudent(const string& name);
    int waitNum() const;

private:
    queue<string> nameQueue;
};


#endif //LAB7_STL_RESTAURANTQUEUE_H
