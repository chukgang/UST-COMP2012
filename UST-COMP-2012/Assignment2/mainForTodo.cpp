/*
 * mainForTodo.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: kevinw
 *
 */


#include "TodoBoard.h"
#include "TodoPlace.h"
#include "TodoRestaurant.h"
#include "TodoPlayer.h"
#include "TodoProperty.h"


//You are not allowed to modify this file
//You are not required to submit this file

int main(void) {
	BoardController* b = new TodoBoardController;
	b->init();
	b->run();
	delete b;

}

/**
 * Do not move this function to your TodoBoard.cpp. It is here for a reason.
 *
 * There are one constructor needed for each of the following classes. You can have
 * more as long as it compiles.
 *
 * TodoPlaceModel(string, COLOR); First parameter is the name of the cell, second parameter is the
 *      color of the cell.
 * TodoRestaurantModel(string, int, COLOR); First parameter is the name of the cell, second is the
 *      selling price, third is the color of the cell.
 * TodoPropertyModel(string, int, COLOR); First parameter is the name of the cell, second is the
 * 		selling price, third is the color of the cell.
 * TodoPlayerModel(string, int, COLOR); First parameter is the name of the player, second is the
 *      cash that the player to start with, third is the color of the player.
 *
 *
 */
void TodoBoardController::init() {
	for (int i = 0; i < BOARD_SIZE; i++) {
		if (i == 0)
			cells[i] = new TodoPlaceModel(PLACES[i], WHITE);
		else if (i % 5 == 4)
			cells[i] = new TodoRestaurantModel(PLACES[i], 3000, GREEN);
		else
			cells[i] = new TodoPropertyModel(PLACES[i], COSTS[i], WHITE);
	}

	for (int i = 0; i < NUMBER_PLAYERS; i++)
		players[i] = new TodoPlayerModel(PLAYERS_NAME[i], START_CASH, PLAYERS_COLOR[i]);

}

