#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int fd;
    char buffer[20];

    // Create a file and write to it
    fd = creat("file.txt", S_IRWXU);
    write(fd, "Hello, World!", 13);
    close(fd);

    // Open the file for reading
    fd = open("file.txt", O_RDONLY);
    read(fd, buffer, 13);
    buffer[13] = '\0'; // Null-terminate the string
    close(fd);

    // Print the content read from the file
    printf("Content of file: %s\n", buffer);

    // Delete the file
    unlink("file.txt");

    return 0;
}

