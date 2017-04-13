/*
 * param.h
 *
 *  Created on: Feb 27, 2017
 *      Author: kevinw
 *
 *  A document holding constant parameter.
 */
//You are not allowed to modify this file
//You are not required to submit this file

#ifndef PARAM_H_
#define PARAM_H_

#define NUMBER_PLAYERS 3
#define BOARD_SIZE 16

#include <string>
using namespace std;

enum Color {RED, BLUE, YELLOW, GREEN, WHITE};

const int START_CASH = 10000;
const int PLACE_CASH = 2000;
const int ROB_CASH = 500;
const int BUILDING_COST = 500;
const int RESTAURANT_COUNT = 3;
const int MAX_HOUSES = 5;

const string PLACES[] = {
		"Sandal",
		"Atrium",
		"Library",
		"Concourse",
		"Cafe",
		"Mushroom",
		"Pool",
		"Room 4210",
		"LT-A",
		"LG5 Fastfood",
		"Sports Hall",
		"Supermarket",
		"Car Park",
		"Gym",
		"LSK Kebba",
		"Bank"
};
const int COSTS[] = {1000, 1000, 2000, 2000, 3000, 3000, 4000, 4000, 5000, 3000, 3000, 3000, 4000, 4000, 5000, 5000};

const string PLAYERS_NAME[] = {"Brian", "Alex", "Desmond"};
const Color PLAYERS_COLOR[] = {GREEN, BLUE, YELLOW};

#endif /* PARAM_H_ */
