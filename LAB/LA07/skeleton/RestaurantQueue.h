#ifndef LAB7_STL_RESTAURANTQUEUE_H
#define LAB7_STL_RESTAURANTQUEUE_H
#include <queue>
#include <iostream>

using namespace std;

class RestaurantQueue {
public:
    void serveStudent(){
    	if(waitNum() == 0){
    		cout << "Current queue is empty." << endl;
    	}else{
    		cout << nameQueue.front() << " is served." << endl;
    		nameQueue.pop();
    	}
    };

    void addStudent(const string& name){
    	cout << name << " is get into the queue." << endl;
    	nameQueue.push(name);
    }

    int waitNum() const{
    	return nameQueue.size();
    };

private:
    queue<string> nameQueue;
};


#endif //LAB7_STL_RESTAURANTQUEUE_H
