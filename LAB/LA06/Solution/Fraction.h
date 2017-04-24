#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction {
  public:
    // Constructors
    Fraction();
    Fraction(const int numerator, const int denominator);

    // Accessors
    int getNumerator() const;
    int getDenominator() const;
    bool getSign() const;

    // Mutator
    void setFraction(const int numerator, const int denominator);

    // Arithmetic operators
    Fraction operator+(const Fraction& f) const;
    Fraction operator-(const Fraction& f) const;
    Fraction operator*(const Fraction& f) const;
    Fraction operator/(const Fraction& f) const;

    // Comparison operators
    bool operator==(const Fraction& f) const;
    bool operator!=(const Fraction& f) const;
    bool operator<(const Fraction& f) const;
    bool operator>(const Fraction& f) const;
    bool operator<=(const Fraction& f) const;
    bool operator>=(const Fraction& f) const;

    // Other functions
    friend ostream& operator<<(ostream& os, const Fraction& f);

  private:
    // Euclidean algorithm - Find gcd of two non-negative integers 
    int gcd(const int a, const int b) const;

    // Member variables
    int numerator, denominator;
};

#endif
