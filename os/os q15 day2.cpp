#include <stdio.h>

int main() {
    FILE *file_ptr = fopen("data/subdirectory/file.txt", "w"); // Create file in a two-level directory structure
    if (file_ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file_ptr, "This is a file organized using a two-level directory structure.\n");
    fclose(file_ptr);
    printf("File 'file.txt' created and written successfully in the 'data/subdirectory' directory!\n");
    return 0;
}

