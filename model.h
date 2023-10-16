#include <stdlib.h>
#include <dirent.h>

#ifndef MAX_PATH_CHARS
#define MAX_PATH_CHARS 50
#endif

#ifndef MODEL_H
#define MODEL_H

#define MAX_DIR_COUNT 20
#define MAX_FILE_COUNT 50
#define MAX_OTHER_COUNT 20

typedef struct Model{
	char path[MAX_PATH_CHARS];

	struct dirent *directories;
	struct dirent *files;
	struct dirent *others;

	int dirsSize;
	int filesSize;
	int othersSize;

	int dirCount;
	int fileCount;
	int otherCount;

	int totalCount;


} Model;

Model createEmptyModel(){
	int direntSize = sizeof(struct dirent);

	Model result;
	result.directories = malloc(MAX_DIR_COUNT * direntSize);
	result.files = malloc(MAX_FILE_COUNT * direntSize);
	result.others = malloc(MAX_OTHER_COUNT * direntSize);

	result.dirsSize = 0;
	result.filesSize = 0;
	result.othersSize = 0;

	/*
	   There are always at least 2 dirs, '.' and '..'
	*/
	result.dirCount = 2;
	result.fileCount = 0;
	result.otherCount = 0;

	result.totalCount = 2; // see prev. comment

	return result;
}

void deleteModel(Model model) {
	free(model.directories);
	free(model.files);
	free(model.others);

}

char* currSelectedEntry(Model model, int cursorPos){
	if (cursorPos < model.dirCount) {
		return model.directories[cursorPos].d_name;
	} else if (cursorPos < model.dirCount + model.fileCount) {
		return model.files[cursorPos - model.dirCount].d_name;
	}
	return "";
}

#endif // MODEL_H
