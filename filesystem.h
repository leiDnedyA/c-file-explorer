#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "model.h"

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

Model modelFromDir(char* dir){
	DIR *folder;
	struct dirent *entry;
	
	// Add some code to validate directory string

	folder = opendir(dir);

	Model model = createEmptyModel();

	strcpy(model.path, dir);

	while ( (entry=readdir(folder)) ) {
		switch(entry->d_type) {
			case DT_REG:
				if (model.fileCount >= MAX_FILE_COUNT) {
					break;
				}
				model.files[model.fileCount] = *entry;
				model.fileCount++;
				model.totalCount++;
				break;
			case DT_DIR:
				if (model.dirCount >= MAX_DIR_COUNT) {
					break;
				}
				// Make sure that '.' is first dir and '..' is 2nd
				if (strcmp((*entry).d_name, ".") == 0) {
					model.directories[0] = *entry;
				}
				else if (strcmp((*entry).d_name, "..") == 0) {
					model.directories[1] = *entry;
				} else {
					model.directories[model.dirCount] = *entry;
					model.dirCount++;
					model.totalCount++;
				}
				break;
			default:
				if (model.otherCount >= MAX_OTHER_COUNT) {
					break;
				}
				model.otherCount++;
				// for now, don't increment total because others
				// aren't displayed
				break;
		}
	}

	closedir(folder);
	
	return model;
}


int isDir(char* fileName) {
	struct stat path;

	stat(fileName, &path);

	return S_ISREG(path.st_mode);
}

#endif
