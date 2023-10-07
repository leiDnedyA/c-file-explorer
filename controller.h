#include <string.h>
#include "view.h"
#include "model.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define UP_KEY_VAL 3 
#define DOWN_KEY_VAL 2
#define SPACE_KEY_VAL 32
#define ENTER_KEY_VAL 10
#define MAX_PATH_CHARS 200

char* navigate(char* startDir) {
	int cursorPos = 0;
	bool terminated = false;
	char* target = (char*) malloc(MAX_PATH_CHARS);

	Model model;

	while (true){
		model = modelFromDir(startDir);
		render(model, cursorPos);
		char lastChar = getch();
		/*
		// Prints out code for last char typed
		printw("%d\n", lastChar);
		getch();
		refresh();
		*/
		if (lastChar == UP_KEY_VAL) {
			if (cursorPos > 0) {
				cursorPos -= 1;
			}
			continue;
		}
		if (lastChar == DOWN_KEY_VAL) {
			if (cursorPos < model.totalCount - 1) {
				cursorPos += 1;
			}
			continue;
		}
		if (lastChar == SPACE_KEY_VAL) {
			// figure out how to check if curr entry is a directory
		}
		strcat(target, "/");
		strcat(target, currSelectedEntry(model, cursorPos));
		break;

	}
	deleteModel(model);

	char* result = malloc(strlen(startDir) + strlen(target) + 2);
	strcpy(result, startDir);
	strcat(result, "/");
	strcat(result, target);

	return result; 
}

#endif
