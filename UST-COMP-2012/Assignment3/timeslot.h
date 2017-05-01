/*
 * timeslot.h
 *
 */

#ifndef TIMESLOT_H_
#define TIMESLOT_H_

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

enum weekday {Mon, Tue, Wed, Thu, Fri};

class Timeslot
{
    /* TODO
     * Please refer to the sample output for output format
     */
    friend ostream& operator<<(ostream& os, const Timeslot& time);

  private:
    static string weekday_string[5];
    weekday day1, day2;
    int start;
    int end;

  public:
    // Constructor
    Timeslot(weekday d1, weekday d2, int stime, int etime);

    // Accessors
    bool match(weekday day) const;
    bool match(int stime, int etime) const;

    /* TODO
     * Convert the day in enum type to a printable string
     * using the static string weekday_string[5].
     */
    string convert(weekday day) const;
};


#endif /* TIMESLOT_H_ */
