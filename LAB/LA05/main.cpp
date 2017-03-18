/*
 * main.cpp
 *
 */
#include <iostream>
#include "Shape.h"
#include "Polygon.h"
#include "Circle.h"

using namespace std;

int main() {
    const int shape_num = 3;
    // Dynamically allocate an array of Shape*
    Shape **shape_vec = new Shape*[shape_num];

    // A Polygon object
    Point2D* points_1 = new Point2D[4];
    points_1[0]=Point2D(0,1);points_1[1]=Point2D(1,1);points_1[2]=Point2D(1,0);points_1[3]=Point2D(0,0);
    Shape *polygon_1 = new Polygon(points_1, 4);

    // Another Polygon object, boundary is a quadratic function
    Point2D* points_2 = new Point2D[10];
    for(int i = 0; i < 9; i ++){
        points_2[i] = Point2D(static_cast<float>(i)/10, static_cast<float>(i*i)/100);
    }
    points_2[9] = Point2D(0, 0.81); //last point of the Polygon to form a close polygon
    Shape *polygon_2 = new Polygon(points_2, 10);


    // A Circle object with center (2,2) and radius=1.0
    Shape *circle = new Circle(Point2D(2, 2), 1.0);

    shape_vec[0] = polygon_1;
    shape_vec[1] = polygon_2;
    shape_vec[2] = circle;

    cout << endl;


    double shape_area = 0;
    double shape_perimeter = 0;
    for (int i = 0; i < shape_num; i++) {
        // Get the area of the shape
        shape_area = shape_vec[i]->calculateArea();
        cout << "The area is " << shape_area << endl;

        // Get the perimeter of the shape
        shape_perimeter = shape_vec[i]->calculatePerimeter();
        cout << "The perimeter is " << shape_perimeter << endl;

        cout << endl;

    }

    // Clean up
    for (int i = 0; i < shape_num; i++) {
        delete shape_vec[i];
    }
    delete[] shape_vec;
    delete[] points_1;
    delete[] points_2;

    return 0;
}
