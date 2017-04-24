#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;

// Euclidean algorithm - Find gcd of two non-negative integers 
int Fraction::gcd(const int a, const int b) const {
  if(b==0)
    return a;
  return gcd(b, a%b);
}

// Constructors
Fraction::Fraction(){
  setFraction(0, 1);
}

Fraction::Fraction(const int numerator, const int denominator){
  setFraction(numerator, denominator);
}

// Accessors
int Fraction::getNumerator() const {
  return abs(numerator);
}

int Fraction::getDenominator() const {
  return denominator;
}

bool Fraction::getSign() const {
  return numerator < 0;
}

// Mutator
void Fraction::setFraction(const int n, const int d) {
  if(d == 0) {
    cout << "Error! Denominator cannot be zero." << endl;
    setFraction(1,1);
    return;
  }

  int sign = ((int)(n<0)+(d<0))%2, normal=gcd(abs(n),abs(d));
  numerator = abs(n) / normal*(sign?-1:1);
  denominator = abs(d) / normal;
}

// Arithmetic operators
Fraction Fraction::operator+(const Fraction& f) const {
  return Fraction(numerator * f.denominator + f.numerator * denominator, denominator * f.denominator);
}

Fraction Fraction::operator-(const Fraction& f) const {
  return Fraction(numerator * f.denominator - f.numerator * denominator, denominator * f.denominator);
}

Fraction Fraction::operator*(const Fraction& f) const {
  return Fraction(numerator * f.numerator, denominator * f.denominator);
}

Fraction Fraction::operator/(const Fraction &f) const {
  return Fraction(numerator * f.denominator, f.numerator * denominator);
}

// Comparison operators
bool Fraction::operator==(const Fraction& f) const {
	return (numerator==f.numerator)&&(denominator==f.denominator);
}

bool Fraction::operator!=(const Fraction& f) const {
	return !(*this==f);
}

bool Fraction::operator<(const Fraction& f) const {
	return (*this-f).getSign();
}

bool Fraction::operator>(const Fraction& f) const {
	return (f-*this).getSign();
}

bool Fraction::operator<=(const Fraction& f) const {
	return !(*this>f);
}

bool Fraction::operator>=(const Fraction& f) const {
	return !(*this<f);
}

// Other functions
ostream& operator<<(ostream& os, const Fraction& f){
  if(f.denominator==1)
    return os << "(" << f.numerator << ")";
  return os << "(" << f.numerator << "/" << f.denominator << ")";
}
