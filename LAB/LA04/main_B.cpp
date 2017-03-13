
#include <iostream>

#include "corgi.h"

using namespace std;

int main() {

    Dog *dog = new Dog(80, 100, 50, 10, 40);
    dog->print();
    dog->move(10);
    dog->boost_heartbeat();
    dog->decrease_heartbeat();
    delete dog;

    cout << "---------------------------------------" << endl;

    Corgi *corgi = new Corgi(80, 100, 50, 18, 35);
    corgi->print();
    corgi->boost_heartbeat();
    corgi->move(12);
    delete corgi;

    return 0;

}
