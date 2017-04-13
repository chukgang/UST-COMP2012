/*
 * This should contain the implementation of the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file
#include "TodoPlayer.h"

//your code goes here

/* code here */

TodoPlayerModel::TodoPlayerModel(const string name, int cash, Color color)
		: PlayerModel(name, cash, color)
{

}

void TodoPlayerModel::gainProperty(PropertyModel* pm)
{
	PropertyModel** realloc;
	realloc = new PropertyModel*[this->propertyCount + 1];
	for (int i = 0; i != this->propertyCount; i++)
	{
		realloc[i] = this->properties[i];
	}
	realloc[this->propertyCount] = pm;
	delete[] this->properties;
	this->properties = realloc;
	this->propertyCount++;
}

bool TodoPlayerModel::isOwning(PropertyModel* pm) const
{
	for (int i = 0; i != this->propertyCount; i++)
	{
		if (this->properties[i] == pm)
		{
			return true;
		}
	}
	return false;
}

/* code end */
