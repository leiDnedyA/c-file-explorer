#include <stdlib.h>
#include <stdio.h>
// #include <ncurses.h>
#include "model.h"

#ifndef VIEW_H
#define VIEW_H 

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void showGreeting() {
//	clear();
	printf("----------------------------------------------\n");
	printf("\tAyden's File Explorer©\n");
	printf("\tPress <Enter> to continue...\n");
	getchar();
}

void render(Model model) {
	printf("Key: " ANSI_COLOR_YELLOW "directory" ANSI_COLOR_RESET " / " ANSI_COLOR_BLUE "file\n" ANSI_COLOR_RESET);
	printf("----------------------------------------------\n");
	int currLine = 0;

	for (int i = 0; i < model.dirCount; i++) {
		printf("%d\t" ANSI_COLOR_YELLOW "%s\n" ANSI_COLOR_RESET, currLine, model.directories[i].d_name);
		currLine++;
	}
	
	for (int i = 0; i < model.fileCount; i++) {
		printf("%d\t" ANSI_COLOR_BLUE "%s\n" ANSI_COLOR_RESET, currLine, model.files[i].d_name);
		currLine++;
	}
	printf("\n");
	printf("Enter a line number, or press q to open the current target directory.\n");
}

#endif // VIEW_H
