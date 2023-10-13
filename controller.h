#include <string.h>
#include <stdbool.h>
#include "view.h"
#include "model.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define MAX_PATH_CHARS 200

void start() {
	showGreeting();
}

char* navigate(char* startDir) {
	bool terminated = false;
	char* target = (char*) malloc(MAX_PATH_CHARS);
	strcpy(target, startDir);

	Model model;

	while (true){
		model = modelFromDir(target);
		render(model);
		char lastInput[4];
		scanf("%s", lastInput);

		if (strcmp(lastInput, ".") == 0) {
			break;
		}

		int cursorPos = atoi(lastInput);

		strcat(target, "/");
		strcat(target, currSelectedEntry(model, cursorPos));
//		break;

	}
	deleteModel(model);

	char* result = malloc(strlen(startDir) + strlen(target) + 2);
	strcpy(result, startDir);
	strcat(result, "/");
	strcat(result, target);

//	return result; 
	return target;
}

void openDir(char* path) {
	showOpenPrompt();
	char optionInput;
	scanf("%c\n", &optionInput);
	// add switch statement for options
}

#endif
