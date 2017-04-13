/*
 * Board.h
 *
 *  Created on: Feb 27, 2017
 *      Author: kevinw
 *
 *
 *
 */

//You are not allowed to modify this file
//You are not required to submit this file


#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"
#include "param.h"
#include "Player.h"
#include "View.h"

/**
 *  This is the Controller class. In this project, we have only one controller.
 *  It is responsible for the overall program running sequence and coordinates
 *  between different model classes and the view class.
 *
 *	The BoardController has some Players (PlayerModel), has a chess board that
 *	is composed by some Cells (CellModel) and a view (View) for display.
 *
 */
class BoardController {
public:
	/**
	 * Constructor
	 */
	BoardController();
	/**
	 * Destructor
	 */
	virtual ~BoardController();

	/**
	 * This function contain a while-loop that ends only when one of the player bankrupt.
	 */
	virtual void run();

	/**
	 * To initialize the setup of the game. It is taken out from the constructor because the subclass
	 * has different setup.
	 */
	virtual void init();

	/**
	 * This function will display a message to user, and request the user to select an input among the
	 * given options. The return value is the index of options that the user has selected.
	 *
	 * @param message: The message to be displayed to the user.
	 * @param options: The options that the users can select, represented in an array of string
	 * @param numOfOptions: The number of options or the size of the array options.
	 * @return the index of the option being selected.
	 *
	 * This function is not virtual. In grading the assignment, TA will manipulate the user input through
	 * this function.
	 */
	int requestInput(string message, const string options[], int numOfOptions) const;

	/**
	 * This function pause and request user to press OK
	 */
	void prompt(string message) const;
protected:
	/**
	 * A static array of pointers of CellModel.
	 */
	CellModel* cells[BOARD_SIZE];
	/**
	 * A static array of players
	 */
	PlayerModel* players[NUMBER_PLAYERS];
	/**
	 * A view class
	 */
	View view;
	/**
	 * To check if any of the player is bankrupt
	 */
	bool checkBankrupt();
	/**
	 * To request the View class to render the chess board.
	 */
	void printBoard();


	/**
	 * This function is not virtual. In grading, TA will insert the data validation code here
	 * to inspect your code. You must use this function to obtain the number of steps a player
	 * needs to move. Never use rand() directly or it is impossible to grade your work.
	 *
	 * @return the number of steps a player walk.
	 */
	int rollDice();
private:
	/**
	 * The following variables are used by the TA when grading. They are not supposed to be used or
	 * understood.
	 */
	int ta_grading_variable;
	int ta_grading_array[100];
	string ta_grading_string[100];
};

#endif /* BOARD_H_ */
