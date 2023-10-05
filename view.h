#include <stdlib.h>
#include <ncurses.h>
#include "model.h"

#ifndef VIEW_H
#define VIEW_H 

void showGreeting() {
	clear();
	printw("----------------------------------------------\n");
	printw("\tAyden's File Explorer©\n");
	printw("\tPress <Enter> to continue...\n");
	refresh();
	getch();
	refresh();
}

void render(Model model, int cursorPos) {
	clear();
	printw("----------------------------------------------\n");
	refresh();
	int currLine = 0;

	for (int i = 0; i < model.dirCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printw("%c\t%s\n", cursor, model.directories[i].d_name);
		refresh();
		currLine++;
	}
	
	for (int i = 0; i < model.fileCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printw("%c\t%s\n", cursor, model.files[i].d_name);
		currLine++;
	}
	printf("\n");
	refresh();
	getch();
	refresh();
}

#endif // VIEW_H
