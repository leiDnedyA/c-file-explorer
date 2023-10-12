#include <string.h>
#include <stdbool.h>
#include "view.h"
#include "model.h"

#ifndef CONTROLLER_H
#define CONTROLLER_H

#define MAX_PATH_CHARS 200

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
		printf("%s\n", lastInput);

		if (strcmp(lastInput, "q") == 0) {
			break;
		}

		int cursorPos = atoi(lastInput);

		strcat(target, "/");
		printf("%s\n", currSelectedEntry(model, cursorPos));
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

#endif
