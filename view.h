#include <stdlib.h>
#include "model.c"

#define clear() printf("\033[H\033[J")

void showGreeting() {
	// clear();
	system("tput clear");
	printf("----------------------------------------------\n");
	printf("\tAyden's File Explorer©\n");
	printf("\tPress <Enter> to continue...\n");
	getchar();
}

void render(int cursorPos, struct dirent *dirs, struct dirent *files, struct dirent *others, int dirCount, int fileCount, int otherCount) {
	clear();
	printf("----------------------------------------------\n");
	int currLine = 0;

	for (int i = 0; i < dirCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, dirs[i].d_name);
		currLine++;
	}
	
	for (int i = 0; i < fileCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, files[i].d_name);
		currLine++;
	}
	printf("\n");
}

void render2(Model model, int cursorPos) {
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

