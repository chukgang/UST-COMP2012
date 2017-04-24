#include <iostream>
#include "Polynomial.h"
using namespace std;

int main(){
  cout << "addCoef cases:" << endl;
  Polynomial p1;
  cout << p1 << endl;
  p1.addCoef(Fraction(4,3),2);
  cout << p1 << endl;
  p1.addCoef(Fraction(-4,3),2);
  cout << p1 << endl;
  p1.addCoef(Fraction(-4,7),3);
  p1.addCoef(Fraction(0,5),10);
  p1.addCoef(Fraction(-3,5),2);
  p1.addCoef(Fraction(2,3),0);
  Polynomial p2(p1);
  p2.addCoef(Fraction(4,5),5);
  cout << p1 << endl;
  cout << p2 << endl;

  cout << endl << "operator= cases:" << endl;
  Polynomial p3,p4;
  p3.addCoef(Fraction(4,7),1);
  p4.addCoef(Fraction(-5,1),3);
  p3=p3;
  p3=p4=p3=p3;
  cout << p3 << endl;
  cout << p4 << endl;

  cout << endl << "operator+ cases:" << endl;
  Polynomial p5,p6,p7;
  p5.addCoef(Fraction(-7,3),4);
  p5.addCoef(Fraction(6,5),1);
  p5.addCoef(Fraction(2,7),6);
  p6.addCoef(Fraction(1,6),2);
  p6.addCoef(Fraction(-5,8),4);
  p6.addCoef(Fraction(3,4),0);
  p7=p5+p6+p5;
  p5=p7+p6;
  cout << p5 << endl;
  cout << p6 << endl;
  cout << p7 << endl;

  cout << endl << "operator- cases:" << endl;
  p6=p7-p5;
  p5=p6-p7-p5;
  cout << p5 << endl;
  cout << p6 << endl;
  cout << p7 << endl;

  cout << endl << "operator* cases:" << endl;
  Polynomial p8,p9,p10,p11;
  p8.addCoef(Fraction(7,1),1);
  p8.addCoef(Fraction(-2,1),4);
  p8.addCoef(Fraction(3,1),3);
  p9.addCoef(Fraction(-4,1),2);
  p9.addCoef(Fraction(5,1),0);
  p9.addCoef(Fraction(2,1),3);
  p10.addCoef(Fraction(-1,1),0);
  p11=p8*p10*p9;
  p10=p10*p8*p8;
  p9=p9*Polynomial();
  cout << p9 << endl;
  cout << p10 << endl;
  cout << p11 << endl;

  cout << endl << "operator+= cases:" << endl;
  Polynomial p12,p13;
  p12.addCoef(Fraction(1,7),2);
  p12.addCoef(Fraction(2,5),6);
  p12.addCoef(Fraction(3,4),5);
  p13.addCoef(Fraction(6,1),3);
  p13.addCoef(Fraction(1,3),0);
  p13.addCoef(Fraction(2,3),1);
  p12+=p13;
  p13+=p12+=p12;
  cout << p12 << endl;
  cout << p13 << endl;

  cout << endl << "operator-= cases:" << endl;
  p12-=p13;
  p13-=p12;
  cout << p12 << endl;
  cout << p13 << endl;

  cout << endl << "All together:" << endl;
  Polynomial p14,p15,p16,p17;
  p14.addCoef(Fraction(2,3),1);
  p14.addCoef(Fraction(7,2),4);
  p14.addCoef(Fraction(-1,6),2);
  p15.addCoef(Fraction(6,4),3);
  p15.addCoef(Fraction(-9,3),4);
  p15.addCoef(Fraction(-3,2),0);
  p16.addCoef(Fraction(1,3),3);
  p16.addCoef(Fraction(-2,4),2);
  p17=p14*p16-p15+p16*p15-p14+p16+p15*p14;
  cout << p17 << endl;

  // Optional part
  /*
  cout << endl << "[Optional] operator/ and operator% cases:" << endl;
  Polynomial p18,p19;
  p18.addCoef(Fraction(4,5),7);
  p18.addCoef(Fraction(-2,1),2);
  p18.addCoef(Fraction(4,3),3);
  p18.addCoef(Fraction(-2,5),4);
  p19.addCoef(Fraction(-1,3),2);
  p19.addCoef(Fraction(2,3),1);
  p19.addCoef(Fraction(3,1),0);
  cout << p18/p19 << endl;
  cout << p18%p19 << endl;
  cout << Polynomial()/p19 << endl;
  */

  return 0;
}
