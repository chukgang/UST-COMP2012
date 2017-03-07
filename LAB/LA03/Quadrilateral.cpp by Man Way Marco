//
//  Quadrilateral.cpp
//  COMP2012 Lab 3 Class Inheritance: Basics
//
//  Created by MarcoMan on 6/3/2017.
//  Copyright © 2017 Man Way Marco. All rights reserved.
//

#include <stdio.h>
#include "Quadrilateral.h"
#include  <iostream>
#include <cmath>
using namespace std;
/*
 class Quadrilateral: public Polygon
 {
	public:
 
 *  Constructor
 *  Check if the number of points is 4 or not.
 *  If not, output "Illegal! Number of points should be 4".
 *  Otherwise, output "Initialized by Quadrilateral's other constructor"
 *
Quadrilateral(const Point2D points[], int numPoints);

*
 *  Destructor
 *  Output "Quadrilateral's destructor!"
 *
~Quadrilateral();


 *  Print list of points, the perimeter, the center and the area of the quadrilateral object
 *
void print() const;

*
 *  Compute the center of the quadrilateral
 *

Point2D center() const;

*
 *  Compute the perimeter of the quadrilateral
 *
double perimeter() const;

*
 *  Compute the area of the quadrilateral
 *
 *  Formula of area of a quadrilateral
 *  =============================
 *  Let (x0, y0), (x1, y1), (x2, y2) and (x3, y3) be the coordinates
 *  of the four vertices, the area can be computed by
 *  abs((x0y1 + x1y2 + x2y3 + x3y0) - (x1y0 + x2y1 + x3y2 + x0y3))/2.0)
 *
 *
double area() const;
};

*/

Quadrilateral::Quadrilateral(const Point2D points[], int numPoints):Polygon(points,numPoints)
{
    if(numPoints!=4)
    {
        cout << "Illegal! Number of points should be 4"<<endl;
        numPoints=0;
        delete [] this->points;
        this->points=NULL;
    }
    cout <<"Initialized by Quadrilateral's other constructor"<<endl;
}

Quadrilateral::~Quadrilateral()
{
    cout <<"Quadrilateral's destructor!"<<endl;
}

void Quadrilateral::print()const
{
    Polygon::print();
    cout << "Quadrilateral's center:";
    center().print();
    cout<<endl;
    cout << "Quadrilateral's perimeter:"<< perimeter()<<endl;
    cout << "Quadrilateral's area:"<< area()<<endl;
    
    
}

Point2D Quadrilateral::center() const
{
    double sum_x = 0;
    double sum_y = 0;
    
    for(int i = 0; i < numPoints;i++)
    {
        sum_x = sum_x + points[i].getX();
        sum_y = sum_y + points[i].getY();
    }
    return Point2D(sum_x/4,sum_y/4);
}

double Quadrilateral::perimeter() const
{
    double perimeter=0;
    for(int i = 0;i<numPoints;i++)
    {   if(i!=(numPoints-1))
        {
            perimeter = perimeter + points[i].distance(points[i+1]);
        }
        else
        {
            perimeter = perimeter + points[i].distance(points[0]);
        }
    }
    return perimeter;
}

double  Quadrilateral::area() const
{
    double area =0 ;
    //abs((x0y1 + x1y2 + x2y3 + x3y0) - (x1y0 + x2y1 + x3y2 + x0y3))/2.0)
    // 0,0)(1,1)(2,0)(1,2)
    // 1*2 0*1
    for (int i=0;i<numPoints;i++)
    {
        if(i!=(numPoints-1))
        {
            area = area + points[i].getX()*points[i+1].getY()-points[i+1].getX()*points[i].getY();
           
        }
        else
        {
            area = area + points[i].getX()*points[0].getY()-points[0].getX()*points[i].getY();

    
        }
    }
    return abs(area/2);

}
