#ifndef HEART_HPP_
#define HEART_HPP_

#include <iostream>

class Heart {
public:
    Heart(int heartbeat, int max_heartbeat, int min_heartbeat);

    ~Heart();

    void boost_heartbeat();

    void decrease_heartbeat();

    int check_heartbeat();
    int get_max_heartbeat();
    int get_min_heartbeat();

private:
    int heartbeat;
    const int max_heartbeat;
    const int min_heartbeat;
};

#endif
