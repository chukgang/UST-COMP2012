/*
 * Circle.h
 * The header file for the class Circle
 */

#ifndef POLY_CIRCLE_H
#define POLY_CIRCLE_H

#include "Shape.h"
#include <cmath>
#include <iostream>
using namespace std;

class Circle : public Shape {
public:
    // Constructor
    // outputs "Circle constructed."
    Circle(Point2D point, double radius_length) : radius(radius_length), centre(point){
    	cout << "Circle constructed." << endl;
	};

    //------your code starts from here------

    // Destructor
    // outputs "Circle destructed.".
    virtual ~Circle(){
    	cout << "Circle destructed." << endl;
	};

    // calculateArea(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // outputs "Circle::calculateArea() is Called! ".
    virtual double calculateArea() override{
    	cout << "Circle::calculateArea() is Called! " << endl;
    	return M_PI*radius*radius;
	};
	
    // calculatePerimeter(). Function prototype here, actual code, if any, in the Circle.cpp file.
    // returns a double value.
    // Print out "Circle::calculatePerimeter() is Called! ".
	virtual double calculatePerimeter() override{
		cout << "Circle::calculatePerimeter() is Called! " << endl;
		return 2*M_PI*radius;
	};
	
    //------your code ends here------

protected:
    double radius;
    Point2D centre;
};


#endif //POLY_CIRCLE_H
