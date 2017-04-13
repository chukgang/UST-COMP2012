/*
 * This should contain the implementation of the class of TodoBoard.
 */

//You need to submit this file
//You need to modify this file
#include "TodoBoard.h"

//your code goes here

/* code here */

TodoBoardController::TodoBoardController()
		: BoardController()
{

}

void TodoBoardController::run()
{
	int turn = 0;
	while (!this->checkBankrupt())
	{
		printBoard();
		int dice = this->rollDice();
		PlayerModel* thisTurnPlayer = this->players[turn];
		stringstream s;
		s << thisTurnPlayer->getName() << ", it is your turn.\n";
		this->view.appendMessage(s.str());
		this->view.displayPlayer(thisTurnPlayer);
		for (int i = 0; i != dice; i++)
		{
			thisTurnPlayer->move(1);
			TodoPlaceModel* place = dynamic_cast<TodoPlaceModel*>(this->cells[thisTurnPlayer->getPosition()]);
			if (place != NULL)
			{
				thisTurnPlayer->collect(PLACE_CASH);
				stringstream msg;
				msg << "[EVENT] collect $" << PLACE_CASH << " at " << this->cells[thisTurnPlayer->getPosition()] << "\n";
				this->view.appendMessage(msg.str());
			}
		}
		for (int i = 0; i != NUMBER_PLAYERS; i++)
		{
			if (thisTurnPlayer != this->players[i] && thisTurnPlayer->getPosition() == this->players[i]->getPosition())
			{
				this->players[i]->pay(ROB_CASH);
				thisTurnPlayer->collect(ROB_CASH);
				stringstream msg;
				msg << "[EVENT] rob $" << ROB_CASH << " from " << this->players[i]->getName() << "\n";
				this->view.appendMessage(msg.str());
			}
		}
		this->printBoard();
		this->cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
}

/* code end */
