/*
 * This should contain the implementation of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file
#include "TodoProperty.h"

//your code goes here

/* code here */

TodoPropertyModel::TodoPropertyModel(const string name, int price, Color color)
		: PropertyModel(name, price, color)
{

}

TodoPropertyModel::~TodoPropertyModel()
{

}

void TodoPropertyModel::action(PlayerModel* player, const BoardController& board)
{
	if (this->owner == NULL)
	{
		int option;
		stringstream s;
		s << "Do you want to buy " << name << "?";
		const string options[2] = {"Yes", "No"};
		option = board.requestInput(s.str(), options, 2);
		if (option == 0)
		{
			if (player->getCash() >= this->price)
			{
				player->pay(this->price);
				player->gainProperty(this);
				stringstream msg;
				msg << "You paid $" << this->price << " for buying " << this->name;
				board.prompt(msg.str());
				this->owner = player;
				this->color = player->getColor();
			}
			else
			{
				board.prompt("Not enough money");
			}
		}
	}
	else if (this->owner == player)
	{
		if (player->getCash() > BUILDING_COST && this->houses < MAX_HOUSES)
		{
			player->pay(BUILDING_COST);
			this->houses++;
			board.prompt("You built a house");
		}
	}
	else
	{
		player->pay(this->getRate());
		this->owner->collect(this->getRate());
		stringstream msg;
		msg << "you paid rent $" << this->getRate() << " to " << this->owner->getName() << "\n";
		board.prompt(msg.str());
	}
}

int TodoPropertyModel::getRate() const
{
	return PropertyModel::getRate();
}

/* code end */
