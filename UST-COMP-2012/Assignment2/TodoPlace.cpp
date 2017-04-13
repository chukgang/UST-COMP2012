/*
 * This should contain the implementation of the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file
#include "TodoPlace.h"
//your code goes here

/* code here */

TodoPlaceModel::TodoPlaceModel(const string name, Color color)
		: CellModel(name, color)
{

}

void TodoPlaceModel::action(PlayerModel* player, const BoardController& board)
{
	stringstream msg;
	msg << "[ACTION] nothing to do at " << this->getName() << "\n";
	board.prompt(msg.str());
}

/* code end */
