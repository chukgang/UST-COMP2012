/*
 * This should contain the class of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODORESTAURANTMODEL_H_
#define TODORESTAURANTMODEL_H_

//your code goes here

/* code here */

#include "TodoProperty.h"
#include "param.h"
#include "Player.h"
#include "Board.h"

#include <string.h>
#include <sstream>

class TodoRestaurantModel: public TodoPropertyModel
{
	public:
		TodoRestaurantModel(const string name, int price, Color color);
		void action(PlayerModel* player, const BoardController& board);
		int getRate() const;
};

/* code end */

#endif /* TODORESTAURANTMODEL_H_ */
