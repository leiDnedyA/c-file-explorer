#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "view.h"
#include "model.h"
#include "launch_terminal.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#ifndef MAX_PATH_CHARS
#define MAX_PATH_CHARS 200
#endif

void start() {
	showGreeting();
}

typedef struct NavigationResult{
	char* targetDir;
	char* option; // user's input other than a number
		      // e.g 't' to open a terminal window
} NavigationResult;

bool stringIsNumber(char* str) {
	for (int i = 0; i < strlen(str); i++) {
		char curr = str[i];
		if ((! (curr >= '0' && curr <= '9')) && !isspace(curr)) {
			return false;
		}
	}
	return true;
}

NavigationResult navigate(char* startDir) {
	bool terminated = false;
	char* target = (char*) malloc(MAX_PATH_CHARS);
	char* inputOption = (char*) malloc(4);
	strcpy(target, startDir);

	Model model;

	while (true){
		model = modelFromDir(target);
		render(model);
		char lastInput[4];
		scanf("%s", lastInput);

		if (!stringIsNumber(lastInput)) {
			strcpy(inputOption, lastInput);
			break;
		}

		int cursorPos = atoi(lastInput);

		strcat(target, "/");
		strcat(target, currSelectedEntry(model, cursorPos));
//		break;

	}
	deleteModel(model);

	char* resultDir = malloc(strlen(startDir) + strlen(target) + 2);
	strcpy(resultDir, startDir);
	strcat(resultDir, "/");
	strcat(resultDir, target);
	
	NavigationResult result = {resultDir, inputOption};

	return result;
}

void openDirectory(char* path, char* option) {
	if (strcmp(option, "t") == 0) {
		openTerminalWindow(path);
	}
	else if (strcmp(option, "n") == 0) {
		openNeovimWindow(path);
	}
	else if (strcmp(option, "b") == 0) {
		openTerminalWindow(path);
		openNeovimWindow(path);
	} else {
		system("clear");
	}
}

void promptOpenOption(char* path) {
	showOpenPrompt(realpath(path, NULL));
	char* optionInput = (char*) malloc(10);
	scanf("%s", optionInput);
	openDirectory(path, optionInput);
}

#endif
