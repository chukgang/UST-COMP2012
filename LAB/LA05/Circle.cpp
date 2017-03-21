/*
 * Circle.cpp
 */


#include "Circle.h"
#include <cmath>
#include <iostream>
using namespace std;

    // Constructor
    // outputs "Circle constructed."
    Circle::Circle(Point2D point, double radius_length) : radius(radius_length), centre(point){
    	cout << "Circle constructed." << endl;
	};

    //------your code starts from here------

    // Destructor
    // outputs "Circle destructed.".
    Circle::~Circle(){
    	cout << "Circle destructed." << endl;
	};

    // calculateArea(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // outputs "Circle::calculateArea() is Called! ".
    double Circle::calculateArea() const{
    	cout << "Circle::calculateArea() is Called! " << endl;
    	return M_PI*radius*radius;
	};

    // calculatePerimeter(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // Print out "Circle::calculatePerimeter() is Called! ".
	double Circle::calculatePerimeter() const{
		cout << "Circle::calculatePerimeter() is Called! " << endl;
		return 2*M_PI*radius;
	};

    //------your code ends here------
