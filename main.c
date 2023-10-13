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

	char* newDir = navigate(".");

	printf("%s\n", newDir);

	openDir(realpath(newDir, NULL));

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
