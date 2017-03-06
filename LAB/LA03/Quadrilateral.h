/*
 * Quadrilateral.h
 * The header file for the class Quadrilateral.h
 */

#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Point2D.h"
#include "Polygon.h"

class Quadrilateral: public Polygon
{
	public:
		/*
		 *  Constructor
		 *  Check if the number of points is 4 or not.
		 *  If not, output "Illegal! Number of points should be 4".
		 *  Otherwise, output "Initialized by Quadrilateral's other constructor"
		 */
		Quadrilateral(const Point2D points[], int numPoints);

		/*
		 *  Destructor
		 *  Output "Quadrilateral's destructor!"
		 */
		~Quadrilateral();

		/*
		 *  Print list of points, the perimeter, the center and the area of the quadrilateral object
		 */
		void print() const;

		/*
		 *  Compute the center of the quadrilateral
		 */

		Point2D center() const;

		/*
		 *  Compute the perimeter of the quadrilateral
		 */
		double perimeter() const;

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
		double area() const;
};

#endif /* QUADRILATERAL_H_ */
