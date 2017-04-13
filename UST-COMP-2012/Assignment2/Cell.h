/*
 * Cell.h
 *
 *  Created on: Feb 27, 2017
 *      Author: kevinw
 *
 */

//You are not allowed to modify this file
//You are not required to submit this file


#ifndef CELL_H_
#define CELL_H_

#include <string>
#include "param.h"
class PlayerModel;
class BoardController;

using namespace std;

/**
 * This is a model class that represent each cell on a chess board. This is an abstract class.
 */
class CellModel {
public:
	/**
	 * Constructor
	 *
	 * @param name: The name of this cell that will be printed on the screen
	 * @param color: The color of this cell
	 */
	CellModel(string name, Color color) : name(name), color(color){}
	/**
	 * Destructor
	 */
	virtual ~CellModel() {};
	/**
	 * Abstract function action is invoked when a player arriving this cell.
	 *
	 * @param player: The player arrives this cell
	 * @param board: The constant reference of the game board.
	 */
	virtual void action(PlayerModel* player, const BoardController& board) = 0;
	/**
	 * The getter of name.
	 *
	 * @return The name of this cell
	 */
	string getName() const {return name;}
	/**
	 * The getter of color
	 *
	 * @return The color of this cell
	 */
	Color getColor() const {return color;}
protected:
	/**
	 * The name of the cell.
	 */
	const string name;
	/**
	 * The color of the cell.
	 */
	Color color;
};

#endif /* CELL_H_ */
