/*
 * Quadrilateral.h
 * The header file for the class Quadrilateral.h
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Point2D.h"
#include "Polygon.h"
#include <stdio.h>
#include "Quadrilateral.h"
#include  <iostream>
#include <cmath>
using namespace std;

class Quadrilateral: public Polygon{

	public:

		/*
		 *  Constructor
		 *  Check if the number of points is 4 or not.
		 *  If not, output "Illegal! Number of points should be 4".
		 *  Otherwise, output "Initialized by Quadrilateral's other constructor"
		 */
		Quadrilateral(const Point2D points[], int numPoints) : Polygon(points, numPoints){
			if(numPoints != 4){
				cout << "Illegal! Number of points should be 4" << endl;
				numPoints = 0;
				delete [] this->points;
				this->points = NULL;
			}else{
				cout << "Initialized by Quadrilateral's other constructor" << endl;
			}
		}

		/*
		 *  Destructor
		 *  Output "Quadrilateral's destructor!"
		 */
		~Quadrilateral(){
			cout << "Quadrilateral's destructor!" << endl;
		}

		/*
		 *  Print list of points, the perimeter, the center and the area of the quadrilateral object
		 */
		void print() const{
			Polygon::print();
			cout << endl;
			cout << "Quadrilateral's center:";
			center().print();
			cout << endl;
			cout << "Quadrilateral's perimeter: " << perimeter() << endl;
			cout << "Quadrilateral's area: " << area() << endl;

		}

		/*
		 *  Compute the center of the quadrilateral
		 */
		Point2D center() const{
			double sumX = 0;
			double sumY = 0;
			for(int i = 0; i < numPoints; i++){
				sumX = sumX + points[i].getX();
				sumY = sumY + points[i].getY();
			}
			return Point2D(sumX/4, sumY/4);

		}

		/*
		 *  Compute the perimeter of the quadrilateral
		 */
		double perimeter() const{
			double perimeter = 0;
			for(int i = 0; i < numPoints; i++){
				if(i < numPoints - 1){
					perimeter = perimeter + points[i].distance(points[i+1]);
				}else{
					perimeter = perimeter + points[i].distance(points[0]);
				}
			}
			return perimeter;
		}

		/*
		 *  Compute the area of the quadrilateral
		 *
		 *  Formula of area of a quadrilateral
		 *  =============================
		 *  Let (x0, y0), (x1, y1), (x2, y2) and (x3, y3) be the coordinates
		 *  of the four vertices, the area can be computed by
		 *  abs((x0y1 + x1y2 + x2y3 + x3y0) - (x1y0 + x2y1 + x3y2 + x0y3))/2.0)
		 *
		 */
		double area() const{
			double area = 0;
			for(int i = 0; i < numPoints; i++){
				if(i < numPoints - 1){
					area = area + points[i].getX()*points[i+1].getY() - points[i+1].getX()*points[i].getY();
				}else{
					area = area + points[i].getX()*points[0].getY() - points[0].getX()*points[i].getY();
				}
			}
			return abs(area/2);
		}
};

#endif /* QUADRILATERAL_H_ */
