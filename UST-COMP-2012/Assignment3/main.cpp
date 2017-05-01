/*
 * main.cpp
 *
 */

#include <iostream>
#include <map>
#include <vector>
#include "bst.h"
#include "avl.h"
#include "student.h"

using namespace std;

int main()
{
    // Create some courses, possibly with pre-requisites
    int pre1[] = { };
    Course c1(1001, Wed, Thu, 9, 10, pre1, 0);
    int pre2[] = { };
    Course c2(1004, Tue, Thu, 1, 3, pre2, 0);
    int pre3[] = { };
    Course c3(1021, Mon, Wed, 12, 1, pre3, 0);
    int pre4[] = { };
    Course c4(1022, Mon, Wed, 8, 10, pre4, 0);
    int pre5[] = { };
    Course c5(1029, Mon, Fri, 8, 10, pre5, 0);
    int pre6[] = { };
    Course c6(1942, Tue, Thu, 11, 1, pre6, 0);
    int pre7[] = { };
    Course c7(1999, Mon, Thu, 15, 17, pre7, 0);
    int pre8[] = {1022};
    Course c8(2011, Mon, Thu, 15, 17, pre8, 1);
    int pre9[] = {2011};
    Course c9(2012, Wed, Fri, 15, 17, pre9, 1);
    int pre10[] = {1004, 1021};
    Course c10(2021, Tue, Fri, 8, 9, pre10, 2);
    int pre11[] = {2011, 1942};
    Course c11(2611, Tue, Thu, 10, 12, pre11, 2);
    int pre12[] = {2012};
    Course c12(3021, Tue, Thu, 12, 14, pre12, 1);
    int pre13[] = {2611, 1004, 2012};
    Course c13(3511, Wed, Fri, 15, 17, pre13, 3);
    int pre14[] = {2012};
    Course c14(4211, Mon, Fri, 11, 13, pre14, 1);
    int pre15[] = {2012};
    Course c15(3111, Tue, Thu, 18, 20, pre15, 1);
    int pre16[] = {2611};
    Course c16(3711, Wed, Fri, 15, 17, pre16, 1);
    int pre17[] = {2012, 1022};
    Course c17(4321, Wed, Fri, 11, 13, pre17, 2);

    // Create the course database using an STL map
    map<int, Course> db;
    db.insert(make_pair(c1.get_code(), c1));
    db.insert(make_pair(c2.get_code(), c2));
    db.insert(make_pair(c3.get_code(), c3));
    db.insert(make_pair(c4.get_code(), c4));
    db.insert(make_pair(c5.get_code(), c5));
    db.insert(make_pair(c6.get_code(), c6));
    db.insert(make_pair(c7.get_code(), c7));
    db.insert(make_pair(c8.get_code(), c8));
    db.insert(make_pair(c9.get_code(), c9));
    db.insert(make_pair(c10.get_code(), c10));
    db.insert(make_pair(c11.get_code(), c11));
    db.insert(make_pair(c12.get_code(), c12));
    db.insert(make_pair(c13.get_code(), c13));
    db.insert(make_pair(c14.get_code(), c14));
    db.insert(make_pair(c15.get_code(), c15));
    db.insert(make_pair(c16.get_code(), c16));
    db.insert(make_pair(c17.get_code(), c17));

    // Create 2 students with the same course plan,
    // one represented by AVL, the other by BST
    int history[] = {1004, 1021, 1022, 1029, 1942};
    Student s1("BST-006", history, 5, BST_CP); // course_plan stored in an AVL
    Student s2("AVL-007", history, 5, AVL_CP); // course_plan stored in a BST
    s1.print_course_history(); // print initial course history of s1
    s2.print_course_history(); // print initial course history of s2
    cout << endl;

    // Add an invalid course that doesn't exist in the DB to the course history 
    s1.update_course_history(db, 1122);
    s1.print_course_history();
    cout << endl;

    // Add two valid completed courses to the course history 
    s1.update_course_history(db, 2011);
    s1.update_course_history(db, 2012);
    s1.print_course_history();  

    s2.update_course_history(db, 2011);
    s2.update_course_history(db, 2012);
    s2.print_course_history();
    cout << endl;

    // Examples of failed enrolments (of courses to the course plan) 
    s1.enroll(db, 1122); // An invalid course
    s1.enroll(db, 3511); // A course whose pre-requisites not in course history
    cout << endl;

    s2.enroll(db, 1122); // An invalid course
    s2.enroll(db, 3511); // A course whose pre-requisites not in course history
    cout << endl;

    
    // Examples of successful enrolments (of courses to the course plan) 
    cout << "After enrolling courses 2611, 1001, 1999, 2021:" << endl;
    s1.enroll(db, 2611); // s1 enrolls courses
    s1.enroll(db, 1001);
    s1.enroll(db, 1999);
    s1.enroll(db, 2021);
    s2.enroll(db, 2611); // s2 enrolls courses
    s2.enroll(db, 1001);
    s2.enroll(db, 1999);
    s2.enroll(db, 2021);

    // Print course plans in the tree format
    s1.print_course_plan_tree(); cout << endl; // BST tree
    s2.print_course_plan_tree(); cout << endl; // AVL tree

    cout << "After further enrolling courses 3021, 4211, 3111, 4321:" << endl;
    s1.enroll(db, 3021);
    s1.enroll(db, 4211);
    s1.enroll(db, 3111);
    s1.enroll(db, 4321);
    s2.enroll(db, 3021);
    s2.enroll(db, 4211);
    s2.enroll(db, 3111);
    s2.enroll(db, 4321);

    // Print course plans in the tree format
    s1.print_course_plan_tree(); cout << endl; // BST tree
    s2.print_course_plan_tree(); cout << endl; // AVL tree

    cout << "S1's course plan -- preorder list format:" << endl;
    s1.list_course_plan(); // Print information of courses in s1's course plan
    cout << endl;
    cout << "S2's course plan -- preorder list format:" << endl;
    s2.list_course_plan(); // Print information of courses in s2's course plan
    cout << endl;

    // Check if some courses are in the course history
    cout << "S1: check if course 2611 is taken" << endl << "Result: ";
    s1.check_course(2611);
    cout << "S1: check if course 3111 is taken" << endl << "Result: ";
    s1.check_course(3111);
    cout << "S1: check if course 9999 is taken" << endl << "Result: ";
    s1.check_course(9999);
    cout << endl;

    cout << "S2: check if course 2611 is taken" << endl << "Result: ";
    s2.check_course(2611);
    cout << "S2: check if course 3111 is taken" << endl << "Result: ";
    s2.check_course(3111);
    cout << "S2: check if course 9999 is taken" << endl << "Result: ";
    s2.check_course(9999);
    cout << endl;
    
    // Print out some courses from a course plan based on course codes
    cout << "Courses in course plan that are above 3000 level:" << endl;
    s1.select_by_code(3000); cout << endl;
    s2.select_by_code(3000); cout << endl;

    // Print out some courses from a course plan based on their lecture days
    cout << "Courses in course plan that are taught on Tuesday:" << endl;
    s1.select_by_day(Tue); cout << endl;
    s2.select_by_day(Tue); cout << endl;

    // Examples of dropping courses
    cout << "After dropping course 2021, 3021, 1001, 4211:" << endl;
    s1.drop(2021);
    s1.drop(3021);
    s1.drop(1001); 
    s1.drop(4211); 

    s2.drop(2021);
    s2.drop(3021); 
    s2.drop(1001); 
    s2.drop(4211);

    s1.list_course_plan(); cout << endl;
    s2.list_course_plan(); cout << endl;

    s1.print_course_plan_tree(); cout << endl;
    s2.print_course_plan_tree(); cout << endl;
    return 0;
}


