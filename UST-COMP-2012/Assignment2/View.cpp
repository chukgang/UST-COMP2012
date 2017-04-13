/*
 * View.cpp
 *
 *  Created on: Mar 7, 2017
 *      Author: kevinw
 */

#include "View.h"
#include <sstream>
#include <cstdlib>
const int MSG_X = 13;
const int MSG_Y = 6;
const int MSG_W = 4 * MSG_X;
const int MSG_H = MSG_Y;

const int COMM_X = 51;
const int COMM_Y = 2 * MSG_Y;
const int COMM_W = MSG_X * 5 - COMM_X;
const int COMM_H = MSG_Y * 3 - COMM_Y;

const int STAT_X = MSG_X;
const int STAT_Y = MSG_Y + MSG_H;
const int STAT_W = COMM_X - STAT_X;
const int STAT_H = COMM_H;

const int CELLS_X[] = { MSG_X * 5, MSG_X * 4, MSG_X * 3, MSG_X * 2, MSG_X, 0, 0, 0, 0, MSG_X , MSG_X * 2, MSG_X * 3 , MSG_X * 4, MSG_X * 5, MSG_X * 5 ,
		MSG_X * 5 };
const int CELLS_Y[] = { MSG_Y * 3, MSG_Y * 3, MSG_Y * 3, MSG_Y * 3 , MSG_Y * 3, MSG_Y * 3 , MSG_Y * 2, MSG_Y , 0, 0, 0, 0, 0, 0, MSG_Y , MSG_Y *2 };
const int CELL_H = MSG_Y;
const int CELL_W = MSG_X;
using namespace std;

View::View() {
	for (int i = 0; i < LOG_SIZE; i++)
		displayLogs[i] = "";
	initscr();
	clear();
	noecho();
	curs_set(0);
	cbreak(); /* Line buffering disabled. pass on everything */

	keypad(stdscr, TRUE);
	raw();
	nonl();

	start_color();

	init_pair(RED, COLOR_WHITE, COLOR_RED);
	init_pair(BLUE, COLOR_WHITE, COLOR_BLUE);
	init_pair(YELLOW, COLOR_BLACK, COLOR_YELLOW);
	init_pair(GREEN, COLOR_BLACK, COLOR_GREEN);
	init_pair(WHITE, COLOR_BLACK, COLOR_WHITE);

	refresh();
	msg_win_box = newwin(MSG_H, MSG_W, MSG_Y, MSG_X);
	box(msg_win_box, 0, 0);
	msg_win = newwin(MSG_H - 2, MSG_W - 2, MSG_Y + 1, MSG_X + 1);

	wrefresh(msg_win);
	stat_win_box = newwin(STAT_H, STAT_W, STAT_Y, STAT_X);
	box(stat_win_box, 0, 0);
	stat_win = newwin(STAT_H - 2, STAT_W - 2, STAT_Y + 1, STAT_X + 1);

	wrefresh(stat_win);
	comm_win_box = newwin(COMM_H, COMM_W, COMM_Y, COMM_X);
	box(comm_win_box, 0, 0);
	comm_win = newwin(COMM_H - 2, COMM_W - 2, COMM_Y + 1, COMM_X + 1);

	for (int i = 0; i < BOARD_SIZE; i++) {
		cells_win_box[i] = newwin(CELL_H, CELL_W, CELLS_Y[i], CELLS_X[i]);
		box(cells_win_box[i], 0, 0);
		cells_win[i] = newwin(CELL_H - 2, CELL_W - 2, CELLS_Y[i] + 1,
				CELLS_X[i] + 1);
		wrefresh(cells_win_box[i]);
	}
	wrefresh(msg_win_box);
	wrefresh(stat_win_box);
	wrefresh(comm_win_box);
	mvprintw(MSG_X - 1 , MSG_Y * 2, "Use Up/Down arrows and Enter/Space to select");
	refresh();
}

View::~View() {
	clrtoeol();
	refresh();
	endwin();

	delwin(comm_win_box);
	delwin(msg_win_box);
	delwin(stat_win_box);

	delwin(comm_win);
	delwin(msg_win);
	delwin(stat_win);
	for (int i = 0; i < BOARD_SIZE; i++) {
		delwin(cells_win[i]);
		delwin(cells_win_box[i]);
	}
}

void View::printCell(int index, const CellModel* cell,
		const PlayerModel* players[]) {
	WINDOW* window = cells_win[index];
	wclear(window);
	wrefresh(window);
	int line = 0;

	wattron(window, COLOR_PAIR(cell->getColor()));
	mvwprintw(window, line++, 0, cell->getName().c_str());
	wattroff(window, COLOR_PAIR(cell->getColor()));
	const PropertyModel *p = dynamic_cast<const PropertyModel*>(cell);
	if (p) {

		if (p->getOwner() == NULL) {
			mvwprintw(window, line++, 0, "Not Owned");
		} else {
			string house = "";
			for (int i = 0; i < p->getHousesCount(); i++)
				house += "H";
			mvwprintw(window, line++, 0, house.c_str());
		}
		stringstream s1;
		s1 << "$" << p->getRate() << endl;
		mvwprintw(window, line++, 0, s1.str().c_str());
	}

	for (int i = 0; i < NUMBER_PLAYERS; i++)
		if (players[i]) {
			wattron(window, COLOR_PAIR(players[i]->getColor()));
			stringstream s;
			s << players[i]->getName().at(0);
			mvwprintw(window, line, 2*i, s.str().c_str());
			wattroff(window, COLOR_PAIR(players[i]->getColor()));
		}
	wrefresh(window);
}

void View::appendMessage(string message) {
	for (int i = LOG_SIZE - 1; i > 0; i--)
		displayLogs[i] = displayLogs[i - 1];
	displayLogs[0] = message.substr(0, MSG_W - 1);
	wclear(msg_win);
	wrefresh(msg_win);
	for (int i = 0; i < LOG_SIZE; i++)
		mvwprintw(msg_win, i, 0, displayLogs[i].c_str());
	wrefresh(msg_win);
}

int View::requestInput(string message, const string options[],
		int numOfOption) const {
	wclear(msg_win);
	wrefresh(msg_win);
	mvwprintw(msg_win, 0, 0, message.c_str());

	for (int i = 0; i < LOG_SIZE -1; i++)
		mvwprintw(msg_win, i + 1, 0, displayLogs[i].c_str());

	wrefresh(msg_win);

	int ch;
	int selectedOption = 0; // to return this value after all;

	renderCommand(options, numOfOption, selectedOption);
    while ((ch = getch()) != KEY_F(1)) {
		switch (ch) {
		case KEY_UP:
			selectedOption--;
			if (selectedOption == -1)
				selectedOption = numOfOption - 1;
			break;
		case KEY_DOWN:
			selectedOption++;
			if (selectedOption >= numOfOption)
				selectedOption = 0;
			break;
		case '\n':
		case KEY_ENTER:
		case '\r':
		case ' ':
			wclear(comm_win);
			wrefresh(comm_win);

			wclear(msg_win);
			wrefresh(msg_win);
			for (int i = 0; i < LOG_SIZE; i++)
				mvwprintw(msg_win, i, 0, displayLogs[i].c_str());
			wrefresh(msg_win);
			return selectedOption;
		}

		renderCommand(options, numOfOption, selectedOption);
		wrefresh(msg_win);
		mvwprintw(msg_win, 0, 0, message.c_str());
		for (int i = 0; i < LOG_SIZE - 1; i++)
			mvwprintw(msg_win, i + 1, 0, displayLogs[i].c_str());
		wrefresh(msg_win);

	}

	exit(1);
}

void View::renderCommand(const string options[], int numOfOption,
		int selectedOption) const {
	wclear(comm_win);

	for (int i = 0; i < numOfOption; i++) {
		if (i == selectedOption) { //highlight that one
			wattron(comm_win, A_REVERSE);
			mvwprintw(comm_win, i, 0, options[i].c_str());
			wattroff(comm_win, A_REVERSE);
		} else
			mvwprintw(comm_win, i, 0, options[i].c_str());
	}
	wrefresh(comm_win);

}

void View::displayPlayer(const PlayerModel* p) {
	wclear(stat_win);
	int line = 0;
	mvwprintw(stat_win, line++, 0, p->getName().c_str());
	stringstream s;
	s << "Cash: " << p->getCash();
	mvwprintw(stat_win, line++, 0, s.str().c_str());
	stringstream s2;
	s2 << "Properties: " << p->getPropertyCount();
	mvwprintw(stat_win, line++, 0, s2.str().c_str());
	wrefresh(stat_win);
}
