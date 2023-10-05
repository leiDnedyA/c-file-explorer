#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
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
	refresh();

	endwin();

	char* sysCall = (char *) malloc(200);
	strcpy(sysCall, "gnome-terminal --working-directory=\"");
	strcat(sysCall, realpath(newDir, NULL));
	strcat(sysCall, "\"");

	system(sysCall);
	system("exit");

//	free(newDir);
//	free(sysCall);

	return 0;
}
