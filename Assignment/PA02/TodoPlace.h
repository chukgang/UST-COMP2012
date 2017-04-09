/*
 * This should contain the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file

//your code goes here
#ifndef TODOPLACE_H_
#define TODOPLACE_H_

#include "Property.h"
#include "param.h"

/**
 *  This is a model class that inherits a cell. A place should not be able to be owned.
 *  When a player passes a place, the player will get some cash, according to the rate calculated.
 */
class TodoPlayerModel;
class TodoBoardController;

class TodoPlaceModel : public PropertyModel {

public:
	/**
	 * Constructor
	 * @param name: the name of this property.
	 * @param color: the initial color of this property.
	 */
	TodoPlaceModel(string name, Color color);

	/**
	 * Destructor.
	 */
	virtual ~TodoPlaceModel();

	/**
	 * The abstract function implemented in this class. When a player passes it, the player will get some cash.
	 * @param player: The player who is currently visiting this property.
	 * @param board: The board controller.
	 */
	virtual void action(PlayerModel* player, const BoardController& board);

	/**
	 * @return the rate that a player can get.
	 */
	virtual int getRate() const;

};

#endif /* TODOPLACE_H_ */
