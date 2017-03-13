#include "heart.h"

using namespace std;

Heart::Heart(int heartbeat, int max_heartbeat, int min_heartbeat): max_heartbeat(max_heartbeat),min_heartbeat(min_heartbeat){
    this->heartbeat = heartbeat;
    cout << "heart is constructed" << endl;
}

Heart::~Heart(){
    cout << "this is the destructor of heart" << endl;
}

void Heart::boost_heartbeat(){
    int tmp = heartbeat + 10;
    heartbeat = tmp > max_heartbeat ? max_heartbeat : tmp;
    cout << "after boosting heartbeat,"
         << "the current heartbeat is " << heartbeat << endl;
}

void Heart::decrease_heartbeat(){
    int tmp = heartbeat - 10;
    heartbeat = tmp < this->min_heartbeat ? min_heartbeat : tmp;
    cout << "after decreasing heartbeat,"
         << "the current heartbeat is " << heartbeat << endl;
}

int Heart::check_heartbeat(){
    return heartbeat;
}

int Heart::get_max_heartbeat(){
    return max_heartbeat;
}

int Heart::get_min_heartbeat(){
    return min_heartbeat;
}
