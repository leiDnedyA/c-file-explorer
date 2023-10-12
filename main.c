#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "model.h"
// #include "view.h"
#include "filesystem.h"
#include "controller.h"

int main() {

//	showGreeting();

	char* newDir = navigate(".");

	printf("%s\n", newDir);

	char* sysCall = (char *) malloc(200);
	strcpy(sysCall, "gnome-terminal --working-directory=\"");
	strcat(sysCall, realpath(newDir, NULL));
	strcat(sysCall, "\"");
	strcat(sysCall, " -- nvim . & bash");

	printf("%s\n", realpath(newDir, NULL));
	system(sysCall);

	return 0;
}
