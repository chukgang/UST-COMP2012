#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include "Fraction.h"
using namespace std;

class Polynomial {
  public:
    // Constructors and destructor
    Polynomial();
    Polynomial(const Polynomial& p);
    ~Polynomial();

    // Mutator
    void addCoef(const Fraction& f, const int deg);

    // Arithmetic operators (+, -, *) Optional: (/, %)
    Polynomial operator+(const Polynomial& p) const;
    Polynomial operator-(const Polynomial& p) const;
    Polynomial operator*(const Polynomial& p) const;
    Polynomial operator/(const Polynomial& p) const;
    Polynomial operator%(const Polynomial& p) const;

    // Assignment operators (=, +=, -=)
    Polynomial& operator=(const Polynomial& p);
    const Polynomial& operator+=(const Polynomial& p);
    const Polynomial& operator-=(const Polynomial& p);

    // Other functions (<<)
    friend ostream& operator<<(ostream& os, const Polynomial& p);

  private:
    // Reduce function
    Polynomial& reduce();

    // Member variables
    Fraction* coef;
    int deg;
};

#endif
