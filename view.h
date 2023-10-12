#include <stdlib.h>
#include <stdio.h>
// #include <ncurses.h>
#include "model.h"

#ifndef VIEW_H
#define VIEW_H 

void showGreeting() {
//	clear();
	printf("----------------------------------------------\n");
	printf("\tAyden's File Explorer©\n");
	printf("\tPress <Enter> to continue...\n");
	getchar();
}

void render(Model model) {
	printf("----------------------------------------------\n");
	int currLine = 0;

	for (int i = 0; i < model.dirCount; i++) {
		printf("%d\t%s\n", currLine, model.directories[i].d_name);
		currLine++;
	}
	
	for (int i = 0; i < model.fileCount; i++) {
		printf("%d\t%s\n", currLine, model.files[i].d_name);
		currLine++;
	}
	printf("\n");
}

#endif // VIEW_H
