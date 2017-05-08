/*
 * student.cpp
 *
 */

#include "student.h"

/* TODO: Constructors
 * - history is a pointer to an int array, storing completed courses
 * - num is the length of this array
 * When cp_type = AVL_CP, store course_plan as an AVL tree; otherwise store course_plan as a BST
 */
Student::Student(const string& id, const int* history, int num, CP_TYPE cp_type)
{
	this->id = id;
	for (int i = 0; i != num; i++)
	{
		this->course_history.insert(history[i]);
	}
	switch (cp_type)
	{
		case BST_CP:
			this->course_plan = new BST<Course, int>;
			break;
		case AVL_CP:
			this->course_plan = new AVL<Course, int>;
			break;
		default:
			this->course_plan = NULL;
	}
}

/* TODO: Add a course into course_history
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::update_course_history(const map<int, Course>& course_db, int code)
{
	if (course_db.find(code) != course_db.end())
	{
		this->course_history.insert(code);
	}
	else
	{
		cout << this->id.c_str() << ": Fail to update history with an invalid course " << code << "\n";
	}
}

/* TODO:
 * Print completed courses in ascending order of the course codes
 * Remark: You should use the STL iterator to go through the course history
 *         which is an STL set.
 */
void Student::print_course_history() const
{
	cout << this->id.c_str() << ": Course history: ";
	for (set<int>::iterator ptr = this->course_history.begin(); ptr != this->course_history.end(); ptr++)
	{
		if (ptr != this->course_history.begin())
		{
			cout << " ";
		}
		cout << *ptr;
	}
	cout << "\n";
}

/* TODO: Add a course into course_plan
 *   course_db is a database containing all valid courses, stored in an STL map
 *   The key values used in the STL map are the course code
 */
void Student::enroll(const map<int, Course>& course_db, int code)
{
	if (course_db.find(code) != course_db.end())
	{
		Course tar = course_db.find(code)->second;
		bool complete = true;
		for (int i = 0; i != tar.get_num_prerequisites(); i++)
		{
			if (this->course_history.find(tar.get_prerequisites(i)) == this->course_history.end())
			{
				complete = false;
				break;
			}
		}
		if (complete)
		{
			this->course_plan->insert(tar, code);
		}
		else
		{
			cout << "Can't enroll COMP" << code << ". Not all pre-requisites are satisfied yet.\n";
		}
	}
}

/* TODO:
 * Remove a course from course_plan
 */
void Student::drop(const int code)
{
	this->course_plan->remove(code);
}

/* TODO: Select courses with course_code larger than base from course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_code(int base)
{
	cout << "Student ID: " << this->id.c_str() << "\n";
	this->course_plan->iterator_init();
	while (!this->course_plan->iterator_end())
	{
		Course tar = this->course_plan->iterator_next();
		if (tar.get_code() > base)
		{
			cout << tar << "\n";
		}
	}
}

/* TODO: Select courses that have lectures on day from the course_plan
 * Remark: Print the selected courses in ascending order of the course codes
 */
void Student::select_by_day(weekday day)
{
	cout << "Student ID: " << this->id.c_str() << "\n";
	this->course_plan->iterator_init();
	while (!this->course_plan->iterator_end())
	{
		Course tar = this->course_plan->iterator_next();
		if (tar.get_time().match(day))
		{
			cout << tar << "\n";
		}
	}
}

/* TODO: Check the details of an enrolled course
 * Remark: Print an appropriate message if the course is not in the course plan
 */
void Student::check_course(int code) const
{
	this->course_plan->iterator_init();
	while (!this->course_plan->iterator_end())
	{
		Course tar = this->course_plan->iterator_next();
		if (tar.get_code() == code)
		{
			cout << tar << "\n";
			return;
		}
	}
	cout << "No\n";
}

/* TODO: Print all courses students plan to take 
 * Remark: Print the courses stored in the BT in preorder format
 */
void Student::list_course_plan() const
{
	cout << "Student ID: " << this->id.c_str() << "\n";
	this->course_plan->preorder_traversal();
}

/* Print course_plan in a readable tree format.
 * DON'T MODIFY THIS FUNCTION
 */
void Student::print_course_plan_tree() const
{
	cout << "Student ID: " << id << endl;
	course_plan->print();
}
