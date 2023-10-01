#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

#define clear() printf("\033[H\033[J")

void view(int cursorPos, struct dirent *dirs, struct dirent *files, struct dirent *others, int dirCount, int fileCount, int otherCount) {
	clear();
	printf("---------------------------------------\n");
	
	int currLine = 0;

	for (int i = 0; i < dirCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, dirs[i].d_name);
		currLine++;
	}
	
	for (int i = 0; i < fileCount; i++) {
		char cursor;
		if (currLine == cursorPos) {
			cursor = '>';
		} else {
			cursor = ' ';
		}
		printf("%c\t%s\n", cursor, files[i].d_name);
		currLine++;
	}
	printf("\n");
}

int main() {
	
	clear();
	printf("\tAyden's File Explorer©\n");
	printf("----------------------------------------------\n");
	printf("Press any key to continue...\n");
	getchar();

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

	view(0, directories, files, others, dirCount, fileCount, otherCount);

	free(directories);
	free(files);
	free(others);

	return 0;
}
