/*
 * Board.cpp
 *
 *  Created on: Feb 27, 2017
 *  Updated on: Apr 4, 2017 fix issue, checkbankrupt 0 shd be excluded
 *      Author: kevinw
 */


//You are not allowed to modify this file
//You are not required to submit this file

#include "Board.h"
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

BoardController::BoardController() {

}

void BoardController::init() {
	for (int i = 0; i < BOARD_SIZE; i++)
		cells[i] = new PropertyModel(PLACES[i], COSTS[i], WHITE);

	for (int i = 0; i < NUMBER_PLAYERS; i++)
		players[i] = new PlayerModel(PLAYERS_NAME[i], START_CASH, PLAYERS_COLOR[i]);
}

BoardController::~BoardController() {
	for (int i = 0; i < BOARD_SIZE; i++)
		delete cells[i];

	for (int i = 0; i < NUMBER_PLAYERS; i++)
		delete players[i];

}

void BoardController::run() {
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
		//Move and Trigger Event
		cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);
		//Next player
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
	prompt("End of Game");


}

bool BoardController::checkBankrupt() {
	for (int i = 0; i < NUMBER_PLAYERS; i++) {
		if (players[i]->getCash() < 0)
			return true;
	}
	return false;
}

void BoardController::printBoard() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		const PlayerModel* p[NUMBER_PLAYERS];
		for (int j = 0; j < NUMBER_PLAYERS; j++)
			if (players[j]->getPosition() == i)
				p[j] = players[j];
			else
				p[j] = NULL;
		view.printCell(i, cells[i], p);
	}


}

int BoardController::requestInput(string message, const string options[], int optionCount) const {
	return view.requestInput(message, options, optionCount);
}

void BoardController::prompt(string message) const {
	string options[] = {"OKAY"};
	view.requestInput(message, options, 1);
}



/**
 * during grading, you are expected this function will be replaced with other functions.
 */
int BoardController::rollDice() {
	return rand() % 6 + 1;
}

