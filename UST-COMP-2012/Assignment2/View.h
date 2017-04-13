/*
 * View.h
 *
 *  Created on: Mar 7, 2017
 *      Author: kevinw
 *
 */

//You may change this file for your own debugging purpose or for fun.
//You are not required to submit this file

#ifndef VIEW_H_
#define VIEW_H_


#ifdef _WIN_
#include "./ncurses_lib/curses.h"
#else
#include <curses.h>
#endif

#include <string.h>
#include "param.h"
#include "Cell.h"
#include "Player.h"

const int LOG_SIZE = 5;
/**
 *  This is the view class of the project. It is responsible to render all displays on screen and receive
 *  all commands from the player. The command received will be returned to the appropriate function, which
 *  wish to receive input from the player.
 *
 *  The current implementation of this class is using a famous library called NCURSES.
 *  https://www.gnu.org/software/ncurses/
 *
 */
class View {
public:
	/**
	 * Constructor
	 */
	View();
	/**
	 * Destructor
	 */
	virtual ~View();
	/**
	 * Rendering a cell. If it is a property it will show more information
	 * @param index: identify which index of the cell is going to be printed
	 * @param cell: the pointer to a cell.
	 * @param players: An array of players that is on this cell. The caller should guarantee that
	 * the array has a size of at least NUMBER_PLAYERS.
	 *
	 * Note: in C++ the array size in function prototype is ignored during compilation. Thus, writing
	 * NUMBER_PLAYERS here is not physically meaningful. However, it hints the programmer that the array
	 * size of the parameter is assumed in the function.
	 */
	void printCell(int index, const CellModel* cell, const PlayerModel* players[NUMBER_PLAYERS]);
	/**
	 * Append a message on screen. Do not feed in change line symbol. Over length message will be trimmed.
	 *
	 * @param: Message to be displayed.
	 */
	void appendMessage(string);
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
	 * This function display the attribute of a player.
	 *
	 * @param player: The player to be displayed on screen.
	 */
	void displayPlayer(const PlayerModel* player);
private:

	void renderCommand(const string[], int, int) const;

	WINDOW *msg_win;
	WINDOW *cells_win[BOARD_SIZE];
	WINDOW *stat_win;
	WINDOW *comm_win;

	WINDOW *msg_win_box;
	WINDOW *cells_win_box[BOARD_SIZE];
	WINDOW *stat_win_box;
	WINDOW *comm_win_box;


	string displayLogs[LOG_SIZE];
};

#endif /* VIEW_H_ */
