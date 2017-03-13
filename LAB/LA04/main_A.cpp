#include <iostream>
#include "lion.h"

using namespace std;

int main() {
	cout << "--------------------------Construction Phase--------------------------------" << endl;
    Animal *a = new Animal(100, 130, 80, 70, 4);


    cout<<"The animal constructed has the following attributes:"<<endl;
    a->print();
    a->grow(10);
    cout<<endl<<endl;

    Lion *b = new Lion(80, 120, 60, 90, 4, 15);
    cout<<"The Lion constructed has the following attributes:"<<endl;
    b->print();
    b->grow(15);
    b->move(20);
    cout<<endl<<endl;


    cout << "--------------------------Destruction Phase---------------------------------" << endl;
    delete a;
    a = b;
    cout<<endl<<"Let's look at the Lion again before destroying it:"<<endl;
    a->print();
    cout<<endl;
    delete b;
    return 0;
}
