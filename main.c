#include <ncurses.h>
#include <stdlib.h>
#include <dirent.h>
#include "model.h"
#include "view.h"
#include "filesystem.h"

int main() {

	/* ncurses setup */

	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();

	showGreeting();

	Model model = modelFromDir(".");

	printw("%s\n", model.directories[0].d_name);
	refresh();

	render(model, 6);

	printw("%s\n", currSelectedEntry(model, 6));
	refresh();

	deleteModel(model);

	endwin();

	return 0;
}
