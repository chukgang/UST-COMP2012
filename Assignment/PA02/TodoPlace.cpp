/*
 * This should contain the implementation of the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file


#include "TodoPlace.h"
//your code goes here
#include "TodoPlayer.h"
#include "TodoBoard.h"
#include <sstream>

using namespace std;

TodoPlaceModel::TodoPlaceModel(string name, Color color) : PropertyModel(name, 0, color){

}

TodoPlaceModel::~TodoPlaceModel() {

}

void TodoPlaceModel::action(PlayerModel* player, const BoardController& board){
	player->collect(this->getRate());
	//board.prompt(player->getName() << " collects cash from " << name);
}

int TodoPlaceModel::getRate() const {
		return PLACE_CASH;
}
