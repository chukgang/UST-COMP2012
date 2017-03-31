/*
 * mainForDemo.cpp
 *
 *  Created on: Mar 10, 2017
 *      Author: kevinw
 */

//You are not allowed to modify this file
//You are not required to submit this file

#include <iostream>
#include "Board.h"

int main(void) {
	BoardController b;
	b.init();
	b.run();
	std::cin.get();
}
