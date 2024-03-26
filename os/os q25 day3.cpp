#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

int main() {
    // Open a file using fcntl
    int fd = open("file.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("File opened successfully\n");

    // Write to the file
    write(fd, "Hello, World!", 13);

    // Seek to the beginning of the file
    lseek(fd, 0, SEEK_SET);

    // Read from the file
    char buffer[20];
    read(fd, buffer, 13);
    buffer[13] = '\0'; // Null-terminate the string
    printf("Content read from file: %s\n", buffer);

    // Get file information using stat
    struct stat file_stat;
    if (stat("file.txt", &file_stat) == -1) {
        perror("Error getting file information");
        return 1;
    }
    printf("File size: %ld bytes\n", file_stat.st_size);

    // Open a directory using opendir
    DIR *directory = opendir(".");
    if (directory == NULL) {
        perror("Error opening directory");
        return 1;
    }
    printf("Directory opened successfully\n");

    // Read directory entries using readdir
    struct dirent *entry;
    printf("Directory contents:\n");
    while ((entry = readdir(directory)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    // Close the directory
    closedir(directory);

    // Close the file
    close(fd);

    return 0;
}

