/*
 * This should contain the class of TodoPlayerModel.
 */

//You need to submit this file
//You need to modify this file
#ifndef TODOPLAYER_H_
#define TODOPLAYER_H_

//your code goes here

/* code here */

#include "Player.h"
#include "param.h"
#include "Property.h"

#include <string.h>

class TodoPlayerModel: public PlayerModel
{
	public:
		TodoPlayerModel(const string name, int cash, Color color);
		void gainProperty(PropertyModel* pm);
		bool isOwning(PropertyModel* pm) const;
};

/* code end */

#endif /* TODOPLAYER_H_ */
