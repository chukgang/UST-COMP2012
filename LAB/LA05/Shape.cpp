/*
 * Shape.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: httpak
 */


#include "Shape.h"
#include <iostream>
using namespace std;


	//------your code starts from here------
    // Constructor.
    // outputs "Constructing a Shape.".
	Shape::Shape(){
    	cout << "Constructing a Shape." << endl;
	};

    // Destructor, should be able to destroy the object according to its dynamic type (i.e. if it is a Circle, should be able to call the destructor of Circle).
    // outputs "Shape destructed."
    Shape::~Shape(){
    	cout << "Shape destructed." << endl;
	};

    // calculateArea()
    // Pure virtual function. Compute the area of the shape.
    // returns a double value.
    //virtual double Shape::calculateArea() = 0;

    // calculatePerimeter()
    // Pure virtual function. Compute the perimeter of the shape.
    // returns a double value.
    //virtual double Shape::calculatePerimeter() = 0;

    //------your code ends here------
