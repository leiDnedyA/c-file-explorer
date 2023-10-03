#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "view.c"

int main() {

	showGreeting();

	DIR *folder;
	struct dirent *entry;

	folder = opendir(".");

	if(folder == NULL) {
		printf("Unable to read directory\n");
	}

	int maxDirCount = 20;
	int maxFileCount = 50;
	int maxOtherCount = 20;

	Model model = createEmptyModel();

	while ( (entry=readdir(folder)) ) {
		switch(entry->d_type) {
			case DT_REG:
				if (model.fileCount >= maxFileCount) {
					break;
				}
				model.files[model.fileCount] = *entry;
				model.fileCount++;
				break;
			case DT_DIR:
				if (model.dirCount >= maxDirCount) {
					break;
				}
				model.directories[model.dirCount] = *entry;
				model.dirCount++;
				break;
			default:
				if (model.otherCount >= maxOtherCount) {
					break;
				}
				model.otherCount++;
				break;
		}
	}

	closedir(folder);

	render2(model, 0);

	free(model.directories);
	free(model.files);
	free(model.others);

	return 0;
}
