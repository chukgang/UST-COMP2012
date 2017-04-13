/*
 * This should contain the implementation of TodoRestaurantModel.
 */

//You need to submit this file
//You need to modify this file
//your code goes here

/* code here */

#include "TodoRestaurant.h"

TodoRestaurantModel::TodoRestaurantModel(const string name, int price, Color color)
		: TodoPropertyModel(name, price, color)
{

}

void TodoRestaurantModel::action(PlayerModel* player, const BoardController& board)
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
			board.prompt("You say yes");
			if (player->getCash() >= this->price)
			{
				player->gainProperty(this);
			}
			else
			{
				board.prompt("Unsuccessful");
			}
		}
		else
		{
			board.prompt("You say no");
		}
	}
	else if (this->owner != player)
	{
		player->pay(this->getRate());
		this->owner->collect(this->getRate());
	}
}

int TodoRestaurantModel::getRate() const
{
	int count = 0;
	for (int i = 0; i != this->owner->getPropertyCount(); i++)
	{
		const PropertyModel* property = this->owner->getProperties()[i];
		const TodoRestaurantModel* restaurant = dynamic_cast<const TodoRestaurantModel*>(property);
		if (restaurant != NULL)
		{
			count++;
		}
	}
	return count * this->price;
}

/* code end */
