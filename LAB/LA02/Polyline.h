#ifndef POLYLINE_H
#define POLYLINE_H
#include <iostream>
#include <cmath>
using namespace std;

class Polyline {
private:
	int currSize;
	const Point** points;
public:
	Polyline() : currSize(0), points(NULL) {};
	Polyline(const Point& p1, const Point& p2)
	{
		if (p1.getDim() == p2.getDim())
		{
			currSize = 2;
			points = new const Point*[currSize];
			points[0] = &p1;
			points[1] = &p2;
		}
		else
		{
			cout << "Error: Dimensions of points in a polyline must be the same." << endl;
			currSize = 0;
			points = NULL;
		}

	}
	Polyline(const Polyline& polyline)
	{
		currSize = polyline.currSize;
		points = new const Point*[currSize];
		for (int i=0; i < currSize ;i++)
		{
			points[i] = polyline.points[i];
		}
	}
	~Polyline()
	{delete [] points;}
	double getLength() const
	{
		double sum_of_length;
		for (int i=0; i < currSize-1 ; i++)
		{
			sum_of_length += points[i]->dist(*points[i+1]);
		}
		return sum_of_length;
	}
	void print() const
	{
		cout << "This polyline contains:" << endl;
		if (currSize != 0)
		{	cout << currSize << endl;
			for (int i = 0; i< currSize;i++)
			points[i]->print();
		cout << endl;
		}
		else
			cout << "No points" << endl;
	}
	void addPoint(const Point& p)
	{
		if (currSize == 0 && points == NULL)
		{
			currSize++;
			points = new const Point*[currSize];
			points[0] = &p;
		}
		else if (points[0]->getDim() != p.getDim())
		{
			cout << "Error: Dimensions of points in a polyline must be the same." << endl;
		}
		else
		{
			const Point** backup = new const Point*[currSize];
			for (int i=0;i<currSize;i++)
			{
				backup[i] = points[i];
			}
			const Point** new_point = new const Point*[currSize+1];
			for (int i=0;i<currSize;i++)
			{
				new_point[i] = backup[i];
			}
			new_point[currSize] = &p;
		}
	}

};
#endif
