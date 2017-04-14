/*
 * This should contain the class of TodoBoardController.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODOBOARDCONTROLLER_H_
#define TODOBOARDCONTROLLER_H_
//your code goes here

/* code here */

#include "Board.h"
#include "TodoPlace.h"
#include "param.h"

#include <sstream>

class TodoBoardController: public BoardController
{
	public:
		TodoBoardController();
		~TodoBoardController();
		void init();
		void run();
};

/* code end */

#endif /* TODOBOARDCONTROLLER_H_ */
