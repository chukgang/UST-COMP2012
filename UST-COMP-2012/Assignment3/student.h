/*
 * Student.h
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <set>
#include <map>
#include <string>

#include "course.h"
#include "bt.h"
#include "bst.h"
#include "avl.h"

enum CP_TYPE { BST_CP, AVL_CP };

class Student
{
  private:
    string id;

    // Contain the course code of all completed courses
    set<int> course_history;

    // Course plan stores courses the student plans to take.
    // It can be stored as either a BST BT or AVL BT.
    BT<Course, int>* course_plan;

  public:
    /* TODO: Constructor */
    Student(const string& id, const int* history, int num, CP_TYPE dbtype);
   
    ~Student() { delete course_plan; }  // Destructor

    /* TODO: Add a course into course_history */
    void update_course_history(const map<int, Course>& course_db, int course_code);

    /* TODO: Print completed courses in ascending order of the course codes */
    void print_course_history() const;

    /* TODO: Add a course into course_plan if it is valid */
    void enroll(const map<int, Course>& course_db, int course_code);

    /* TODO: Remove a course from course_plan */
    void drop(int code);

    /* TODO: Select courses with course_code larger than base_code from course_plan
     * Remark: Print the selected courses in ascending order of the course codes
     */
    void select_by_code(int base_code);

    /* TODO: Select courses that have lectures on day from the course_plan
     * Remark: Print the selected courses in ascending order of the course codes
     */
    void select_by_day(weekday day);

    /* TODO: Check the details of an enrolled course
     * Remark: Print an appropriate message if the course is not in the course plan
     */
    void check_course(int code) const;

    /* TODO: Print all courses students plan to take 
     * Remark: Print the courses stored in the BT in preorder format
     */
    void list_course_plan() const;

    /* Print course_plan in a readable tree format.
     * DON'T MODIFY THIS FUNCTION
     */
    void print_course_plan_tree() const;
};


#endif /* STUDENT_H_ */
