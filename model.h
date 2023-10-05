#include <stdlib.h>
#include <dirent.h>

#define MAX_DIR_COUNT 20
#define MAX_FILE_COUNT 50
#define MAX_OTHER_COUNT 20

#ifndef MODEL_H
#define MODEL_H

typedef struct Model{
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

	result.dirCount = 0;
	result.fileCount = 0;
	result.otherCount = 0;

	result.totalCount = 0;

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
