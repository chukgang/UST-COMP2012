/*
 * Property.cpp
 *
 *  Created on: Feb 27, 2017
 *      Author: kevinw
 */

#include "Property.h"
#include "Player.h"
#include "Board.h"
#include <sstream>

using namespace std;
//You are not allowed to modify this file
//You are not required to submit this file

PropertyModel::PropertyModel(string name, int price, Color color) : CellModel(name, color), price(price), houses(0), owner(NULL) {
}

PropertyModel::~PropertyModel() {
}

void PropertyModel::action(PlayerModel* p, const BoardController& b) {
	if (owner == NULL) {
		//allow to buy
		int option;

		stringstream s;
		s << "Do you want to buy " << name <<"?";
		const string options[2] = {"Yes" , "No"};

		option = b.requestInput(s.str(), options, 2);
		if (option == 0) {
				p->gainProperty(this);
				b.prompt("You say yes, but you can't buy in demo");
		} else {
				b.prompt("You say no, you can't buy in demo anyway");

		}
	} 
}


int PropertyModel::getRate() const {
	if (owner == NULL)
		return price;
	return price * ( houses + 1)  * 3 / 4;
}

