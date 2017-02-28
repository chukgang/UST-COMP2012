#include <iostream> 
#include <cmath> 
#include <Point.h> 
using namespace std  

Point::Point(const int dim, const int* co)：dimension（dim）{
  coordinates = new int[dimension];
  for (int i = 0; i < dimension; i++){
    coordinates[i] = co[i];  
  }
} 	









Point(const Point& p); 	~Point(); 	int getDim() const; 	double dist(const Point& p) const; 	void print() const; 	void translate(const int dim, const int diff); };
