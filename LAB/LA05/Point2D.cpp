/*
 * Point2D.cpp
 *
 */

#include <iostream>
#include <cmath>
#include <limits>
#include "Point2D.h"

using namespace std;

// Copy constructor
Point2D::Point2D(const Point2D &p) {
    x = p.x;
    y = p.y;
}

// Construct a point with given coordinates
Point2D::Point2D(double x_in, double y_in) : x(x_in), y(y_in) {
}

// Destructor
Point2D::~Point2D() {
}

// Check whether two 2D points_ptr are the same
bool Point2D::equal(const Point2D &p) const {
    bool x_boolean = fabs(x - p.x) < numeric_limits<double>::epsilon();
    bool y_boolean = fabs(y - p.y) < numeric_limits<double>::epsilon();
    return (x_boolean && y_boolean);
}

// Print the 2D point
void Point2D::print() const {
    cout << "(" << x << "," << y << ")";
}

// Compute the distance between 2D points_ptr
double Point2D::distance(const Point2D &p) const {
    double tmp_d;
    tmp_d = sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    return tmp_d;
}

// Get the coordinate of x
double Point2D::getX() const {
    return x;
}

// Get the coordinate of y
double Point2D::getY() const {
    return y;
}
