#include <stdlib.h>
#include <string.h>
#include <dirent.h>
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
				model.directories[model.dirCount] = *entry;
				model.dirCount++;
				model.totalCount++;
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

#endif
