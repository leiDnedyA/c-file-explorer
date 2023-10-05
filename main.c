#include <ncurses.h>
#include <stdlib.h>
#include <dirent.h>
#include "model.h"
#include "view.h"
#include "filesystem.h"
#include "controller.h"

int main() {

	/* ncurses setup */

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	showGreeting();

	char* newDir = navigate(".");

	printw("%s\n", newDir);
	getch();
	refresh();

	endwin();

	return 0;
}
