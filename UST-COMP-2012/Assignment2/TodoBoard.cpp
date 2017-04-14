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

TodoBoardController::~TodoBoardController()
{
	for (int i = 0; i != BOARD_SIZE; i++)
	{
		delete this->cells[i];
	}
	for (int i = 0; i != NUMBER_PLAYERS; i++)
	{
		delete this->players[i];
	}
}

void TodoBoardController::run()
{
	int turn = 0;
	while (!this->checkBankrupt())
	{
		printBoard();
		int dice = this->rollDice();
		PlayerModel* thisTurnPlayer = this->players[turn];
		this->view.displayPlayer(thisTurnPlayer);
		stringstream s;
		s << thisTurnPlayer->getName() << ", it is your turn. Dice: " << dice << "\n";
		this->prompt(s.str());
		this->view.appendMessage(s.str());
		for (int i = 0; i != dice; i++)
		{
			thisTurnPlayer->move(1);
			TodoPlaceModel* place = dynamic_cast<TodoPlaceModel*>(this->cells[thisTurnPlayer->getPosition()]);
			if (place != NULL)
			{
				thisTurnPlayer->collect(PLACE_CASH);
				stringstream msg;
				msg << "[EVENT] collect $" << PLACE_CASH << " at " << this->cells[thisTurnPlayer->getPosition()]->getName() << "\n";
				this->prompt(msg.str());
				this->printBoard();
				this->view.displayPlayer(thisTurnPlayer);
			}
		}
		for (int i = 0; i != NUMBER_PLAYERS; i++)
		{
			if (thisTurnPlayer != this->players[i] && thisTurnPlayer->getPosition() == this->players[i]->getPosition())
			{
				this->players[i]->pay(ROB_CASH);
				thisTurnPlayer->collect(ROB_CASH);
				this->printBoard();
				this->view.displayPlayer(thisTurnPlayer);
				stringstream msg;
				msg << "[EVENT] rob $" << ROB_CASH << " from " << this->players[i]->getName() << "\n";
				this->prompt(msg.str());
			}
		}
		this->printBoard();
		this->view.displayPlayer(thisTurnPlayer);
		this->cells[thisTurnPlayer->getPosition()]->action(thisTurnPlayer, *this);
		this->view.displayPlayer(thisTurnPlayer);
		this->prompt("End turn for " + thisTurnPlayer->getName());
		turn = (turn + 1) % NUMBER_PLAYERS;
	}
	this->prompt("End of Game");
	this->printBoard();
	exit(0);
}

/* code end */
