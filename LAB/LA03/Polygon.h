/*
 * Polygon.h
 * The header file for the class Polygon
 */

#ifndef POLYGON_H
#define POLYGON_H

#include "Point2D.h"
#include <stdio.h>
#include "Polygon.h"
#include <iostream>
using namespace std;

class Polygon{

	public:

		/*
		 *  Default constructor
		 *  Output "Initialized by Polygon's default constructor"
		 *  Set n_points to 0 and points to NULL
		 */
		Polygon() : numPoints(0), points(NULL){
			cout << "Initialized by Polygon's default constructor" << endl;
		}

		/*
		 *  Copy constructor
		 *  Output "Initialized by Polygon's other constructor", and
		 *  perform deep copying
		 */
		Polygon(const Polygon& s) : numPoints(s.numPoints){
			points = new Point2D[numPoints];
			for(int i = 0; i < numPoints; i++){
				points[i] = s.points[i];
			}
			cout << "Initialized by Polygon's other constructor" << endl;
		}

		/*
		 *  Other constructor
		 *  Output "Initialized by Polygon's other constructor", and
		 *  perform deep copying
		 */
		Polygon(const Point2D points[], int numPoints) : numPoints(numPoints){
			this->points = new Point2D[numPoints];
			for(int i = 0; i < numPoints; i++){
				this->points[i] = points[i];
			}
			cout << "Initialized by Polygon's other constructor" << endl;
		}

		/*
		 *  Destructor
		 *  Output "Polygon's destructor!" and destruct all the points
		 */
		~Polygon(){
			delete []points;
			cout << "Polygon's destructor" << endl;
		}

		/*
		 *  Print the list of 2D points in the set and the number of the points
		 *  Check if the number of points is 0. If so, output "The Polygon is empty!".
		 *  Otherwise, output the number of points of polygon and all the points.
		 */
		void print() const{
			if(numPoints == 0){
				cout << "The Polygon is empty!" << endl;
			}else{
				cout << " Number of points:" << numPoints << endl;
				for(int i = 0; i < numPoints; i++){
					points[i].print();
					if(i < numPoints -1){
						cout << ",";
					}
				}
			}
		}

	protected:
		int numPoints;
		Point2D *points;
};

#endif
