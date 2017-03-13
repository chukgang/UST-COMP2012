#ifndef DOG_HPP_
#define DOG_HPP_

#include "heart.h"

using namespace std;

class Dog : private Heart    // Private inheritance
{
public:

    // Constructor of Dog
    Dog(int heartbeat, int max_heartbeat, int min_heartbeat, int speed, int weight) : Heart(heartbeat, max_heartbeat, min_heartbeat), speed(speed), weight(weight){
    	cout << "Dog is constructed" << endl;
	};

    // Destructor of Dog
    ~Dog(){
    	cout << "this is the destructor of dog" << endl;
	};

    //This function will move the dog for the given time duration with the speed, refer to the output for the details
    void move(int time){
    	cout << "this dog moved " << time*speed << " meters in " << time << " seconds" << endl;
	};

    //prints the heart info, it will be used in the print() function
    void print_heart_info(){
        cout << "heartbeat: " << check_heartbeat()
             << "\tmax_heartbeat: " << get_max_heartbeat()
             << "\tmin_heartbeat: " << get_min_heartbeat();
    }

    //print the dog information (including heart information, weight and speed)
    void print(){
    	print_heart_info();
    	cout << "	weight: " << get_weight() << "	speed: " << get_speed() << endl;
	};

    //get the heart information
    int check_heartbeat(){
    	Heart::check_heartbeat();
	};
    int get_max_heartbeat(){
    	Heart::get_max_heartbeat();
	};
    int get_min_heartbeat(){
    	Heart::get_min_heartbeat();
	};

    //get the weight and speed information of the Dog
    int get_weight(){
    	return weight;
	};
    int get_speed(){
    	return speed;
	};

    //change the state of heart these two function should call the corresponding functions in the Heart class
    void boost_heartbeat(){
    	Heart::boost_heartbeat();
	};
    void decrease_heartbeat(){
    	Heart::decrease_heartbeat();
	};

private:
    int speed;
    int weight;

};

#endif
