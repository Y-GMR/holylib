#include "holylib.h"

void clean() {
	int sweep;
	while ((sweep = getchar()) != '\n' && sweep != EOF);
}

void pause() {
	printf("\n\n> > > Press ENTER to continue < < <\n");
	getchar();
}

int holyscanf(void *output, char type, int size) {
	char input[1024];

	if (fgets(input, sizeof(input), stdin)) {
		if (strchr(input, '\n') == NULL && strlen(input) == sizeof(input) - 1) {
			clean();
		}
		
		input[strcspn(input, "\n")] = 0;
		
		switch (type) {
			case 's': {
				strncpy((char *)output, input, size - 1);
				((char *)output)[size - 1] = 0;
				return 1;
			}
			case 'd': {
				if (sscanf(input, "%d", (int *)output) == 1) {
					return 1;
				} else {
					printf("\nERROR: invalid input for an int!");
					pause();
					return 0;
				}
			}
			case 'f': {
				if (sscanf(input, "%f",  (float *)output) == 1) {
					return 1;
				} else {
					printf("\nERROR: invalid input for a float!");
					pause();
					return 0;					
				}
			}
		}		
	}
	return 0;		
}
