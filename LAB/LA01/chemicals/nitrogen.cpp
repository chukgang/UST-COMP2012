#include "nitrogen.h"
#include <iostream>

using namespace std;

Nitrogen::Nitrogen()
{
	cout << "Constructing Nitrogen..." << endl;
}

void Nitrogen::sayTheName() const
{
	cout << "There is Nitrogen!" << endl;
}
