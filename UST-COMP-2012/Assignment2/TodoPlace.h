/*
 * This should contain the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file
//your code goes here
#ifndef TODOPLACE_H_
#define TODOPLACE_H_

/* code here */

#include "param.h"
#include "Cell.h"
#include "Player.h"
#include "Board.h"

#include <string.h>
#include <sstream>

class TodoPlaceModel: public CellModel
{
	public:
		TodoPlaceModel(const string name, Color color);
		void action(PlayerModel* player, const BoardController& board);
};

/* code end */

#endif /* TODOPLACE_H_ */
