/*
 * course.h
 *
 */

#ifndef COURSE_H_
#define COURSE_H_

#include <vector>
#include "timeslot.h"

class Course
{
    // Print out courses using an overloaded operator<< 
    friend ostream& operator<<(ostream& os, const Course& course);

  private:
    int course_code;    // Course codes are unique
    Timeslot lecture_time;
    vector<int> pre_requisites; // Course codes of pre-requisites of this course

  public:
    /* TODO
     * Constructor: The STL vector, pre_requisites, is initialized from 
     *    an int array prerequisites of size pre_num
     */
    Course(int code, weekday day1, weekday day2, int stime, int etime, int* prerequisites, int pre_num);

    // Accessors
    int get_code() const;
    const Timeslot& get_time() const;

    /* TODO: Accessor
     * Return the number of pre_requisite courses
     */
    int get_num_prerequisites() const;

    /* TODO: Accessor
     * Return the index-th element in pre_requisites
     */
    int get_prerequisites(int index) const;
};



#endif /* COURSE_H_ */
