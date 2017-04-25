/*
  COMP2012 2017S Lab08
  Header file of the average class: average.h
 */

#ifndef AVERAGE_H
#define AVERAGE_H

#include "sum.h"

template <typename T>
class Average : private Sum<T>
{
  private:
    int size;

  public:
    Average(const T& v, int s) : Sum<T>(v), size(s) {}

    void operator()(const T& i){
    	Sum<T>::operator()(i);
    	size++;
    };

    int getSize() const{
    	return size;
    };

    friend ostream& operator<<(ostream& os, const Average& a){
    	
    	os << a.getSum() / a.getSize();
    	return os;
    };
};

//TODO write your code here

#endif /* AVERAGE_H */
