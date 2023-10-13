#include <unistd.h>
#include <string.h>

#ifndef LAUNCH_TERMINAL_H
#define LAUNCH_TERMINAL_H

void openTerminalWindow(char* path) {

	char* sysCall = (char *) malloc(200);
	strcpy(sysCall, "gnome-terminal --working-directory=\"");
	strcat(sysCall, path);
	strcat(sysCall, "\"");

	system(sysCall);

	
}

void openNeovimWindow(char* path) {

	char* sysCall = (char *) malloc(200);
	strcpy(sysCall, "gnome-terminal --working-directory=\"");
	strcat(sysCall, path);
	strcat(sysCall, "\"");
	strcat(sysCall, " -- bash -c 'nvim . ; bash'");

	system(sysCall);

}

#endif
