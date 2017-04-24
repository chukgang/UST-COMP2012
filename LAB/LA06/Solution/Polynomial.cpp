#include <iostream>
#include "Polynomial.h"
using namespace std;

// Constructors and destructor
Polynomial::Polynomial(){
  deg = 0;
  coef = new Fraction[1];
  coef[0].setFraction(0,1);
}

Polynomial::Polynomial(const Polynomial& p){
  deg = p.deg;
  coef = new Fraction[deg+1];
  for(int i=0; i<deg+1; i++)
    coef[i] = p.coef[i];
}

Polynomial::~Polynomial(){
  delete[] coef;
}

// Reduce function
Polynomial& Polynomial::reduce(){
  while(!coef[deg].getNumerator())
    deg--;

  // special case when all coefficients are zero
  if(deg==-1)
    deg++;

  Fraction* temp = new Fraction[deg+1];
  for(int i=0; i<deg+1; i++)
    temp[i] = coef[i];
  delete[] coef;
  coef = temp;

  return *this;
}

// Mutator
void Polynomial::addCoef(const Fraction& f, const int deg){
  if(this->deg<deg){
    Fraction* temp = new Fraction[deg+1]();   // array of default constructors
    for(int i=0; i<this->deg+1; i++)
      temp[i] = coef[i];
    delete[] coef;
    coef = temp;
    this->deg = deg;
  }
  coef[deg] = coef[deg]+f;
  reduce();
}

// Arithmetic operators
Polynomial Polynomial::operator+(const Polynomial& p) const {
  Polynomial temp(*this);
  for(int i=p.deg; i>=0; i--)
    temp.addCoef(p.coef[i],i);
  return temp;
}

Polynomial Polynomial::operator-(const Polynomial& p) const {
  Polynomial temp(*this);
  for(int i=p.deg; i>=0; i--)
    temp.addCoef(p.coef[i]*Fraction(-1,1),i);
  return temp;
}

Polynomial Polynomial::operator*(const Polynomial& p) const {
  Polynomial temp;
  for(int i=deg; i>=0; i--)
    for(int j=p.deg; j>=0; j--)
      temp.addCoef(coef[i]*p.coef[j],i+j);
  return temp;
}

Polynomial Polynomial::operator/(const Polynomial& p) const {
  if(deg>p.deg||(deg==p.deg&&coef[deg]>=p.coef[p.deg])){
    Polynomial temp;
    temp.addCoef(coef[deg]/p.coef[p.deg],deg-p.deg);
    return temp+(*this-temp*p)/p;
  }
  return Polynomial();
}

Polynomial Polynomial::operator%(const Polynomial& p) const {
  return *this-*this/p*p;
}

// Assignment operators
Polynomial& Polynomial::operator=(const Polynomial& p){
  if(this != &p){  
    delete[] coef;
    deg = p.deg;
    coef = new Fraction[deg+1];
    for(int i=0; i<deg+1; i++)
      coef[i] = p.coef[i];
  }
  return *this;
}

const Polynomial& Polynomial::operator+=(const Polynomial& p){
  for(int i=p.deg; i>=0; i--)
    addCoef(p.coef[i],i);
  return *this;
}

const Polynomial& Polynomial::operator-=(const Polynomial& p){
  for(int i=p.deg; i>=0; i--)
    addCoef(p.coef[i]*Fraction(-1,1),i);
  return *this;
}

// Other functions
ostream& operator<<(ostream& os, const Polynomial& p){
  os << p.coef[p.deg] << "x" << p.deg;
  for(int i=p.deg-1; i>=0; i--)
    os << " + " << p.coef[i] << "x" << i;
  return os;
}
