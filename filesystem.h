#include <stdlib.h>
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

	while ( (entry=readdir(folder)) ) {
		switch(entry->d_type) {
			case DT_REG:
				if (model.fileCount >= MAX_FILE_COUNT) {
					break;
				}
				model.files[model.fileCount] = *entry;
				model.fileCount++;
				break;
			case DT_DIR:
				if (model.dirCount >= MAX_DIR_COUNT) {
					break;
				}
				model.directories[model.dirCount] = *entry;
				model.dirCount++;
				break;
			default:
				if (model.otherCount >= MAX_OTHER_COUNT) {
					break;
				}
				model.otherCount++;
				break;
		}
	}

	closedir(folder);
	
	return model;
}

#endif
