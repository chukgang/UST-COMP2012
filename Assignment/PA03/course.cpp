/*
 *course.cpp
 */

#include "course.h"

/* TODO
 * Constructor: The STL vector, pre_requisites, is initialized from an int array
 *   prerequisites of size pre_num
 */
Course::Course(int code, weekday day1, weekday day2, int stime, int etime,
               int* prerequisites, int pre_num)
{ }

// Accessors
int Course::get_code() const
{
    return course_code;
}

const Timeslot& Course::get_time() const
{
    return lecture_time;
}

/* TODO
 * Return the number of pre_requisite courses
 */
int Course::get_num_prerequisites() const
{

}

/* TODO
 * Return the index-th element in pre_requisites
 */
int Course::get_prerequisites(int index) const
{
    
}

/* Print out courses using an overloaded operator<< 
 * DON'T MODIFY THIS FUNCTION
 */
ostream& operator<<(ostream& os, const Course& course)
{
    os << "COMP" << course.course_code
       << "\tLecture time: " << course.lecture_time
       << "\tPre-Requisites: ";

    for(int i = 0; i < course.pre_requisites.size(); i++)
        os << course.pre_requisites[i] << " ";

    return os;
}

