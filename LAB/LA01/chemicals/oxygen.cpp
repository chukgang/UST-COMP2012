#include "oxygen.h"
#include <iostream>

using namespace std;

Oxygen::Oxygen()
{
	cout << "Constructing Oxygen..." << endl;
}

void Oxygen::sayTheName() const
{
	cout << "There is Oxygen!" << endl;
}
