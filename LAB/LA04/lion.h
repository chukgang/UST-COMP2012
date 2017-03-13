#ifndef LION_HPP_
#define LION_HPP_

#include <iostream>
#include "animal.h"

using namespace std;

class Lion : public Animal {
public:
	//Constructor of Lion
    Lion(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs, int speed) : Animal(heartbeat, max_heartbeat, min_heartbeat, weight, num_of_legs), speed(speed){
		cout << "the lion is constructed" << endl;
	};

    //Destructor of Lion
    ~Lion(){
    	cout << "this is the destructor of lion" << endl;
	};

    //This function will move the lion for the given time duration with the speed, refer to the output for the details
    void move(int time){
    	cout << "this lion moved " << speed*time << " meters in " << time << " seconds" << endl;
	};

    //This function will grow the lion for weight units, refer to the output for the details
    void grow(int weight){
    	Animal::grow(weight);
	};

    //This function prints the information of the Lion, refer to the output for the details
    void print(){
    	Animal::print();
	};

private:
    int speed;
};

#endif
