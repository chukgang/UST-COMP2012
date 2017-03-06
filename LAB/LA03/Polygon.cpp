//
//  Polygon.cpp
//  COMP2012 Lab 3 Class Inheritance: Basics
//
//  Created by MarcoMan on 6/3/2017.
//  Copyright © 2017 Man Way Marco. All rights reserved.
//

#include <stdio.h>
#include "Polygon.h"
#include <iostream>

using namespace std;
/*class Polygon
{
public:
    *
     *  Default constructor
     *  Output "Initialized by Polygon's default constructor"
     *  Set n_points to 0 and points to NULL
     *
    Polygon();
    
    *
     *  Copy constructor
     *  Output "Initialized by Polygon's other constructor", and
     *  perform deep copying
     *
    Polygon(const Polygon& s);
    
    *
     *  Other constructor
     *  Output "Initialized by Polygon's other constructor", and
     *  perform deep copying
     *
    Polygon(const Point2D points[], int numPoints);
    
    *
     *  Destructor
     *  Output "Polygon's destructor!" and destruct all the points
     *
    ~Polygon();
    
    *
     *  Print the list of 2D points in the set and the number of the points
     *  Check if the number of points is 0. If so, output "The Polygon is empty!".
     *  Otherwise, output the number of points of polygon and all the points.
     *
    void print() const;
    
protected:
    int numPoints;
    Point2D *points;
};

*/

Polygon::Polygon():numPoints(0),points(0){cout<<"Initialized by Polygon's default constructor"<<endl;}

Polygon::Polygon(const Polygon& s):numPoints(s.numPoints){
    
    cout << "Initialized by Polygon's other constructor" <<endl;
    points = new Point2D[numPoints];
    for(int i=0;i<numPoints;i++)
    {
        points[i]=s.points[i];
    }
}

Polygon::Polygon(const Point2D points[], int numPoints):numPoints(numPoints)
{
    cout << "Initialized by Polygon's other constructor" <<endl;
    this->points = new Point2D[numPoints];
    for(int i=0;i<numPoints;i++)
    {
        this->points[i]=points[i];
    
    }
}

Polygon::~Polygon()
{
    cout<<"Polygon's destructor!"<<endl;
    delete []points;
}

void Polygon::print()const
{
    if(numPoints==0)
    {
    cout <<"The Polygon is empty!"<<endl;
    
    }
    else
    {
        cout << "Number of points:" << numPoints<<endl;

        cout << "Points:";
        for(int i=0;i<numPoints;i++)
        {
            points[i].print();
            if(i!=(numPoints-1))
                { cout<<",";}
        }
        cout <<endl;
    }
    
}

