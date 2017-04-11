/*
 * This should contain the implementation of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file

//your code goes here

#include "TodoProperty.h"
#include "TodoPlayer.h"
#include "TodoBoard.h"
#include <sstream>

using namespace std;

TodoPropertyModel::TodoPropertyModel(string name, int price, Color color) : PropertyModel(name, price, color){

}

TodoPropertyModel::~TodoPropertyModel() {

}

void TodoPropertyModel::action(PlayerModel* player, const BoardController& board){
	if(owner == NULL){
		//allow to buy
		int option;

		stringstream yes_no;
		yes_no << "Do you want to buy " << name <<"?";
		const string options[2] = {"Yes" , "No"};

		option = board.requestInput(yes_no.str(), options, 2);
		if(option == 0){
			if(player->getCash() >= this->getRate()){
				player->gainProperty(this);
				this->owner = player;
				this->color = player->getColor();
				string s;
				s = player->getName() + " bought " + name;
				board.prompt(s);
			}else{
				board.prompt("You don't have enough money to buy it.");
			}
		}
	}else if(owner == player){
		if(houses < MAX_HOUSES){
			if(player->getCash() >= BUILDING_COST){
				houses += 1;
				player->pay(BUILDING_COST);
				string s;
				s = player->getName() + " builds a house on " + name;
				board.prompt(s);
			}
		}
	}else{
		player->pay(this->getRate());
		this->getOwner()->collect(this->getRate());
		string s;
		s = player->getName() + " pays " + this->getOwner()->getName() + " $" + static_cast<ostringstream*>( &(ostringstream() << this->getRate()) )->str();
		board.prompt(s);
	}
	string s;
	s = player->getName() + ": this round complete.";
	board.prompt(s);
}


int TodoPropertyModel::getRate() const {
	if(owner == NULL){
		return price;
	}else{
		return price * ( houses + 1)  * 3 / 4;
	}
}
