#include <stdlib.h>
#include "model.h"

#ifndef VIEW_H
#define VIEW_H 

#define clear() printf("\033[H\033[J")

void showGreeting() {
	// clear();
	system("tput clear");
	printf("----------------------------------------------\n");
	printf("\tAyden's File Explorer©\n");
	printf("\tPress <Enter> to continue...\n");
	getchar();
}

void render(Model model, int cursorPos) {
	clear();
	printf("----------------------------------------------\n");
	int currLine = 0;

	for (int i = 0; i < model.dirCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, model.directories[i].d_name);
		currLine++;
	}
	
	for (int i = 0; i < model.fileCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, model.files[i].d_name);
		currLine++;
	}
	printf("\n");
}

#endif // VIEW_H
