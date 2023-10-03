#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include "model.h"
#include "view.h"
#include "filesystem.h"

int main() {

	showGreeting();

	Model model = modelFromDir(".");

	printf("%s\n", model.directories[0].d_name);

	render(model, 6);

	printf("%s\n", currSelectedEntry(model, 6));

	deleteModel(model);

	return 0;
}
