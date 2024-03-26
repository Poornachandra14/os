#include <stdio.h>

int main() {
    FILE *file_ptr = fopen("data/file.txt", "w"); // Create file in a single-level directory
    if (file_ptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    fprintf(file_ptr, "This is a file organized using a single-level directory.\n");
    fclose(file_ptr);
    printf("File 'file.txt' created and written successfully in the 'data' directory!\n");
    return 0;
}

