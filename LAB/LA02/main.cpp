#include <iostream>
#include "Point.h"
#include "Polyline.h"

using namespace std;

int main(){
	/* Point valid cases*/
	cout << "Point general constructor/dist:" << endl;
	int co1[][2]={ {3,2}, {-7,22} };
	Point p1(2,co1[0]), p2(2,co1[1]);
	cout << "Distance between ";
	p1.print();
	cout << " and ";
	p2.print();
	cout << " is " << p1.dist(p2) << endl;

	cout << endl << "Point copy constructor/translate/dist:" << endl;
	Point p3(p1), p4(p1);
	p3.translate(1,5);
	p4.translate(2,-7);
	cout << "Distance between ";
	p3.print();
	cout << " and ";
	p4.print();
	cout << " is " << p4.dist(p3) << endl;
	cout << "For previous case, distance between ";
	p1.print();
	cout << " and ";
	p2.print();
	cout << " is still " << p1.dist(p2) << endl;

	cout << endl << "Point getDim:" << endl;
	int co2[]={3,4,5}, co3[]={4,5,6,7,8,9,10};
	Point p5(3,co2), p6(7,co3);
	cout << "Point ";
	p5.print();
	cout << " has a dimension of " << p5.getDim() << endl;
	cout << "Point ";
	p6.print();
	cout << " has a dimension of " << p6.getDim() << endl;


	/* Point invalid cases */
	cout << endl << "Point invalid dist:" << endl;
	p5.dist(p6);
	p6.dist(p5);

	cout << endl << "Point invalid translate:" << endl;
	p5.translate(4,-1);
	cout << "The point is still: ";
	p5.print();
	cout << endl;
	p6.translate(8,3);
	cout << "The point is still: ";
	p6.print();
	cout << endl;
	p6.translate(9,5);
	cout << "The point is still: ";
	p6.print();
	cout << endl;


	/* Polyline valid cases */
	cout << endl << "Polyline default constructor/addPoint/getLength:" << endl;
	int co4[][2]={ {2,3}, {3,5}, {2,8}, {2,-2}, {-3,-5}, {6,10} };
	Point p7(2,co4[0]), p8(2,co4[1]), p9(2,co4[2]), p10(2,co4[3]), p11(2,co4[4]), p12(2,co4[5]);

	Polyline l1;
	l1.print();
	l1.addPoint(p7);
	l1.addPoint(p8);
	l1.addPoint(p9);
	l1.print();
	cout << "The length of this polyline is " << l1.getLength() << endl;

	cout << endl << "Polyline general constructor/addPoint/getLength:" << endl;
	Polyline l2(p7,p8);
	l2.addPoint(p9);
	l2.addPoint(p10);
	l2.addPoint(p11);
	l2.print();
	cout << "The length of this polyline is " << l2.getLength() << endl;

	cout << endl << "Polyline copy constructor/addPoint/getLength:" << endl;
	Polyline l3(l2);
	l3.addPoint(p12);
	l3.print();
	cout << "The length of this polyline is " << l3.getLength() << endl;
	cout << "The length of the old polyline is still " << l2.getLength() << endl;


	/* Polyline invalid cases */
	int co5[][3]={ {1,2,3}, {4,5,6} }, co6[]={2,3};
	Point p13(3,co5[0]), p14(3,co5[1]), p15(2,co6);

	cout << endl << "Polyline invalid general constructor:" << endl;
	Polyline l4(p13,p15);
	l4.print();

	cout << endl << "Polyline invalid addPoint:" << endl;
	Polyline l5(p13,p14);
	l5.print();
	l5.addPoint(p15);
	l5.print();


	/* All combined */
	cout << endl << "All combined:" << endl;
	int co7[][5] = { {1,2,4,-7,9}, {-4,3,6,11,0}, {2,0,7,-6,5}, {3,9,6,2,1}, {2,4,-2,4,0}, {-3,-6,3,-6,0}, {1,2,-1,2,0} };
	Point p16(5,co7[0]), p17(5,co7[1]), p18(5,co7[2]), p19(5,co7[3]), p20(5,co7[4]), p21(5,co7[5]), p22(5,co7[6]), p23(p16);
	Polyline l6(p16,p17);
	l6.addPoint(p18);
	l6.addPoint(p19);
	l6.addPoint(p20);
	Polyline l7(l6);
	l7.addPoint(p21);
	l7.addPoint(p22);
	p23.translate(5,22);
	p23.translate(4,-23);
	l7.addPoint(p23);
	p17.translate(2,16);
	p18.translate(3,-5);
	l7.print();
	cout << "The length of this polyline is " << l7.getLength() << endl;
	
	return 0;
}
