/*
  COMP2012 2017S Lab08
  Header file of the water class: water.h
*/


#ifndef WATER_H
#define WATER_H

class Water
{
  private:
    float weight;

  public:
    Water() : weight(0) {};
    Water(int w) : weight(w) {};

    Water operator+(const Water& a);

    Water operator/(const int& i);

    friend ostream& operator<<(ostream& os, const Water& w){
    	os << w.weight;
    	return os;
	}

};

//TODO: write your code here
    Water Water::operator+(const Water& a){
    	this->weight = this->weight + a.weight;
    	return *this;
    }

    Water Water::operator/(const int& i){
    	this->weight = this->weight / i;
    	return *this;
    }

#endif /* WATER_H */
