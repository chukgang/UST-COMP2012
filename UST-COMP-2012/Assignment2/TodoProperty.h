/*
 * This should contain the class of TodoPropertyModel.
 */

//You need to submit this file
//You need to modify this file

#ifndef TODOPROPERTY_H_
#define TODOPROPERTY_H_

//your code goes here

/* code here */

#include "Property.h"
#include "TodoPlayer.h"
#include "TodoBoard.h"
#include "param.h"

#include <string.h>
#include <sstream>

class TodoPropertyModel: public PropertyModel
{
	public:
		TodoPropertyModel(const string name, int price, Color color);
		virtual ~TodoPropertyModel();
		virtual void action(PlayerModel* player, const BoardController& board);
		virtual int getRate() const;
};

/* code end */

#endif /* TODOPROPERTY_H_ */
