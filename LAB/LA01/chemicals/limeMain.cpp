#include <iostream>
#include "calcium.h"
#include "oxygen.h"

using namespace std;

int main()
{
	Calcium calcium1;

	const Oxygen* oxygen = new Oxygen;

	calcium1.sayTheName();
	oxygen->sayTheName();

	cout << "And we have lime (carbon dioxide)! yahoooooo" << endl;

	delete oxygen;

	//note: we do not need to "delete" nitrogen2, why?

	return 0;
}
