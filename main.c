#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
#include "view.h"
#include "filesystem.h"
#include "controller.h"
#include "launch_terminal.h"

int main() {

	start();

//	char* targetDir; char* option;
	NavigationResult navResult = navigate(".");

	while (isDir(navResult.targetDir) != 0) {
		// Display some sort of message, or simply open the file in nvim
		// If message displayed, go back to navigation in target dir
		return 0;
	}

	if (strcmp(navResult.option, ".") == 0) {
		promptOpenOption(navResult.targetDir);
	} else {
		openDirectory(realpath(navResult.targetDir, NULL), navResult.option);
	}

// 	opens menu to see different options

//	openTerminalWindow(realpath(newDir, NULL));

	/*
	char* sysCall = (char *) malloc(200);
	strcpy(sysCall, "gnome-terminal --working-directory=\"");
	strcat(sysCall, realpath(newDir, NULL));
	strcat(sysCall, "\"");
	strcat(sysCall, " -- bash -c 'nvim . ; bash'");

	printf("%s\n", realpath(newDir, NULL));
	system(sysCall);
	*/

	return 0;
}
