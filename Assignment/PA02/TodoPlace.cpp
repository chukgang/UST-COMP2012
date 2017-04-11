/*
 * This should contain the implementation of the class of TodoPlaceModel.
 */

//You need to submit this file
//You need to modify this file


#include "TodoPlace.h"
//your code goes here
#include "TodoPlayer.h"
#include "Cell.h"
#include "TodoBoard.h"
#include <sstream>

using namespace std;

TodoPlaceModel::TodoPlaceModel(string name, Color color) : CellModel(name, color){

}

TodoPlaceModel::~TodoPlaceModel() {

}

void TodoPlaceModel::action(PlayerModel* player, const BoardController& board){

}
