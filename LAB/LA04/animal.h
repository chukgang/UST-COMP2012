#ifndef ANIMAL_HPP_
#define ANIMAL_HPP_

#include <iostream>
#include "heart.h"

using namespace std;

class Animal {
public:
	//Constructor of Animal
    Animal(int heartbeat, int max_heartbeat, int min_heartbeat, int weight, int num_of_legs) : weight(weight), num_of_legs(num_of_legs), heart(heartbeat, max_heartbeat, min_heartbeat){
    	cout << "animal is constructed" << endl;
	};

    //Destructor of Animal
    ~Animal(){
    	cout << "this is the destructor of animal" << endl;
	};

    //a function that will increase the weight of an animal
    void grow(int weight){
    	this->weight = this->weight + weight;
    	cout << "this animal growed for " << weight << " kg and its weight now is " << this->weight << " kg" << endl;
	};


    //print the information related to the animal see the output for more information
    void print(){
    	cout << "heartbeat: " << check_heartbeat() << "	max_heartbeat: " << get_max_heartbeat() << "	min_heartbeat: " << get_min_heartbeat() << "	weight: " << weight << "	num_of_legs: " << num_of_legs << endl;
	};

    //get the heart information
    int check_heartbeat(){
    	heart.check_heartbeat();
	};
    int get_max_heartbeat(){
    	heart.get_max_heartbeat();
	};
    int get_min_heartbeat(){
    	heart.get_min_heartbeat();
	};

    //get the various attributes of the animal
    int get_weight(){
    	return weight;
	};
    int get_legs(){
    	return num_of_legs;
	};

private:
    int weight;
    int num_of_legs;
    Heart heart;
};

#endif
