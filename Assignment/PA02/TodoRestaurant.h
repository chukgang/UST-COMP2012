/*
 * This should contain the class of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODORESTAURANTMODEL_H_
#define TODORESTAURANTMODEL_H_

//your code goes here

#include "TodoProperty.h"
#include "param.h"

class TodoPlayerModel;
class TodoBoardController;
/**
 *  This is a model class that inherits a cell. A property should be able to be owned.
 *  When a property is owned by a player, any other player stepping on this property
 *  will be charged by some cash, according to the rate calculated.
 */

class TodoRestaurantModel : public TodoPropertyModel {

public:
	/**
	 * Constructor
	 *
	 * @param name: the name of this property.
	 * @param price: the selling price of this property.
	 * @param color: the initial color of this property.
	 */
	TodoRestaurantModel(string name, int price, Color color);

	/**
	 * Destructor.
	 */
	virtual ~TodoRestaurantModel();

	/**
	 * The abstract function implemented in this class. When a player steps on it, he can buy it if
	 * it is not previously owned. He need to pay for the rent if it is owned by other player. He can build
	 * a house if he owned this property before this function is invoked. When there are five houses on
	 * this property, no more house can be built.
	 *
	 * @param player: The player who is currently visiting this property.
	 * @param board: The board controller.
	 */
	virtual void action(PlayerModel* player, const BoardController& board);

	/**
	 * If the property is not owned by any player. The rate is set as the selling price of this property.
	 * When the property is owned by a player, the rate is the rent which is calculated by the
	 * formula: (selling price) * ( number of houses + 1) * 3 / 4;
	 *
	 * @return the selling price or the rate of the rent.
	 */
	virtual int getRate() const;


//	/**
//	 * The getter function of the owner of this property.
//	 */
//	PlayerModel* getOwner() const {return owner;}

	/**
	 * Increase the restaurantCount of the owner of this property
	 */
	void  getRestaurantCount() const;

protected:

//	/**
//	 * The owner of this property.
//	 */
//	PlayerModel* owner;

	/**
	 * The owner of this property.
	 */
	TodoPlayerModel* todoOwner;

};

#endif /* TODORESTAURANTMODEL_H_ */
