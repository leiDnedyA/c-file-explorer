#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "model.c"

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

	int dirCount = 0;
	int fileCount = 0;
	int otherCount = 0;

	int direntSize = sizeof(struct dirent);

	struct dirent *directories = malloc(maxDirCount * direntSize);
	struct dirent *files = (struct dirent*) malloc(maxFileCount * direntSize);
	struct dirent *others = (struct dirent*) malloc(maxOtherCount * direntSize);

	while ( (entry=readdir(folder)) ) {
		switch(entry->d_type) {
			case DT_REG:
				if (fileCount >= maxFileCount) {
					break;
				}
				files[fileCount] = *entry;
				fileCount++;
				break;
			case DT_DIR:
				if (dirCount >= maxDirCount) {
					break;
				}
				directories[dirCount] = *entry;
				dirCount++;
				break;
			default:
				if (otherCount >= maxOtherCount) {
					break;
				}
				otherCount++;
				break;
		}
	}

	closedir(folder);

	render(0, directories, files, others, dirCount, fileCount, otherCount);

	free(directories);
	free(files);
	free(others);

	return 0;
}
