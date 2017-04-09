/*
 * This should contain the implementation of the class of TodoBoard.
 */

//You need to submit this file
//You need to modify this file

#include "TodoBoard.h"

//your code goes here

#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

TodoBoardController::TodoBoardController() : BoardController() {

}

//void TodoBoardController::init() {
//	for (int i = 0; i < BOARD_SIZE; i++) {
//		if (i == 0)
//			cells[i] = new TodoPlaceModel(PLACES[i], WHITE);
//		else if (i % 5 == 4)
//			cells[i] = new TodoRestaurantModel(PLACES[i], 3000, GREEN);
//		else
//			cells[i] = new TodoPropertyModel(PLACES[i], COSTS[i], WHITE);
//	}
//
//	for (int i = 0; i < NUMBER_PLAYERS; i++)
//		players[i] = new TodoPlayerModel(PLAYERS_NAME[i], START_CASH, PLAYERS_COLOR[i]);
//
//}

TodoBoardController::~TodoBoardController() {
	for (int i = 0; i < BOARD_SIZE; i++){
		delete cells[i];
	}
	for (int i = 0; i < NUMBER_PLAYERS; i++){
		delete players[i];
	}
}

void TodoBoardController::run() {
	int turn = 0;

	while (!checkBankrupt()) {
		//Print Board
		printBoard();
		//Row dice
		int x = rollDice();
		PlayerModel* thisTurnPlayer = players[turn];
		stringstream s;
		s << thisTurnPlayer->getName() << ", it is your turn." << endl;
		view.appendMessage(s.str());
		view.displayPlayer(thisTurnPlayer);
		thisTurnPlayer->move(x);
		printBoard();
		//Did the Player walk pass Place?
		if(thisTurnPlayer->getPosition() - x < 0){
			thisTurnPlayer->collect(PLACE_CASH);
			string s;
			s = thisTurnPlayer->getName() + " collect fees from " + PLACES[0];
			this->prompt(s);
		}
		for(int i = 0; i < NUMBER_PLAYERS; i++){
			if(i == turn){
				continue;
			}else{
				if(players[i]->getPosition() == thisTurnPlayer->getPosition()){
					thisTurnPlayer->collect(ROB_CASH);
					players[i]->pay(ROB_CASH);
					string s;
					s = thisTurnPlayer->getName() + " rob " + players[i]->getName();
					this->prompt(s);
				}
			}
		}
		//Move and Trigger Event
		cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);
		//Next player
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
	prompt("End of Game");
}

//bool TodoBoardController::checkBankrupt() {
//	for (int i = 0; i < NUMBER_PLAYERS; i++) {
//		if (players[i]->getCash() < 0)
//			return true;
//	}
//	return false;
//}

//void TodoBoardController::printBoard() {
//	for (int i = 0; i < BOARD_SIZE; i++) {
//		const PlayerModel* p[NUMBER_PLAYERS];
//		for (int j = 0; j < NUMBER_PLAYERS; j++)
//			if (players[j]->getPosition() == i)
//				p[j] = players[j];
//			else
//				p[j] = NULL;
//		view.printCell(i, cells[i], p);
//	}
//}

//int TodoBoardController::requestInput(string message, const string options[], int optionCount) const {
//	return view.requestInput(message, options, optionCount);
//}
//
//void TodoBoardController::prompt(string message) const {
//	string options[] = {"OKAY"};
//	view.requestInput(message, options, 1);
//}



///**
// * during grading, you are expected this function will be replaced with other functions.
// */
//int TodoBoardController::rollDice() {
//	return rand() % 6 + 1;
//}

