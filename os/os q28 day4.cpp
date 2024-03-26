#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <search_string> <file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char search_string[MAX_LINE_LENGTH];
    strcpy(search_string, argv[1]);

    FILE *file = fopen(argv[2], "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, search_string) != NULL) {
            printf("%s", line);
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}

