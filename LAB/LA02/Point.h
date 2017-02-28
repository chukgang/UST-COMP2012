#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using namespace std;

class Point {
private:
	const int dimension;
	int* coordinates;
public:
	Point(const int dim, const int* co):dimension(dim){
		coordinates = new int [dimension];
		 for (int i = 0; i < dimension ; i++){
			coordinates[i] = co[i];
		 }
	}
	
	Point(const Point& p) : dimension(p.dimension){
		coordinates = new int [dimension];
		 for (int i = 0; i < dimension ; i++){
			coordinates[i] = p.coordinates[i];
		 }
	}
	
	~Point() {
		delete []coordinates;
	}
	
	int getDim() const{
		return dimension;
	}
	
	double dist(const Point& p) const{
		if (dimension != p.dimension){
			cout << "Error: Dimensions of two points do not match." << endl;
		}else{
			double* diff = new double [dimension];
			for (int i= 0; i< dimension; i++){
				diff[i] = p.coordinates[i] - coordinates[i];
			}
			double sum_of_diff = 0;
			for (int j = 0; j< dimension; j++){
				sum_of_diff += diff[j]*diff[j];
			}
			delete diff;
			return sqrt(sum_of_diff);
		}
		return 0;
	}
	
	void print() const{
		cout << "(" ;
		 for (int i=0; i<dimension;i++) {
			 cout << coordinates[i];
			 if (i != dimension -1){
				 cout << ", ";
			 }
		 }
		 cout << ")";
	}
	
	void translate(const int dim, const int diff){
		if (dim > dimension){
			cout << "Error: Dimension is invalid." << endl;
		}else{
			coordinates[dim-1]+= diff;
		}
	}
};

#endif
