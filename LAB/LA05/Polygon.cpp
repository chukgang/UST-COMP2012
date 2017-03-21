/*
 * Polygon.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: httpak
 */



#include "Polygon.h"
#include <iostream>
using namespace std;

    // outputs "Polygon constructed."
    Polygon::Polygon(Point2D *points, int numPoints) : n_points(numPoints){
    	points_ptr = new Point2D[numPoints];
    	for(int i = 0; i < numPoints; i ++){
    		points_ptr[i] = points[i];
		}
    	cout << "Polygon constructed." << endl;
	};

    //------your code starts from here------

    // Destructor. Function prototype here, actual code, if any, in the Polygon.cpp file.
    // outputs "Polygon destructed."
	Polygon::~Polygon(){
		cout << "Polygon destructed." << endl;
	};

    // calculateArea(). Function prototype here, actual code, if any, in the Polygon.cpp file.
    // assume the points are arranged in the clockwise order, direct application of the Shoelace formula shown at the lab page to get the area.
    // absolute value can be derived using the abs() function, which is in the "cmath" library.
    // returns a double value.
    // outputs "Polygon::calculateArea() is Called!".
    double Polygon::calculateArea() const{
    	double areaSum = 0.0;
    	for(int i = 0; i < n_points - 1; i++){
    		areaSum += abs(points_ptr[i].getX()*points_ptr[i+1].getY()+-points_ptr[i+1].getX()*points_ptr[i].getY());
		}
    	areaSum = areaSum +  points_ptr[n_points-1].getX()*points_ptr[0].getY() - points_ptr[0].getX()*points_ptr[n_points-1].getY();
    	cout << "Polygon::calculateArea() is Called!" << endl;
    	return areaSum/2;
	};

    // calculatePerimeter(). Function prototype here, actual code, if any, in the Polygon.cpp file.
    // returns a double value.
    // outputs "Polygon::calculatePerimeter() is Called! ".
	double Polygon::calculatePerimeter() const{
		double perimeterSum = 0.0;
		for(int i = 1; i < n_points; i++){
			perimeterSum += points_ptr[i].distance(points_ptr[i-1]);
		}
		perimeterSum += points_ptr[0].distance(points_ptr[n_points-1]);
		cout << "Polygon::calculatePerimeter() is Called! " << endl;
		return perimeterSum;
	};

    //------your code ends here------
