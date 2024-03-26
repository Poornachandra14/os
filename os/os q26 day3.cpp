#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file_ptr;
    char data[] = "Hello, World!";
    char buffer[20];

    // Write to a file
    file_ptr = fopen("file.txt", "w");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    fputs(data, file_ptr);
    fclose(file_ptr);
    printf("Data written to file successfully\n");

    // Read from a file
    file_ptr = fopen("file.txt", "r");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    fgets(buffer, sizeof(buffer), file_ptr);
    fclose(file_ptr);
    printf("Data read from file: %s\n", buffer);

    // Append to a file
    file_ptr = fopen("file.txt", "a");
    if (file_ptr == NULL) {
        perror("Error opening file");
        return 1;
    }
    fputs(" Appended data", file_ptr);
    fclose(file_ptr);
    printf("Data appended to file successfully\n");

    return 0;
}

