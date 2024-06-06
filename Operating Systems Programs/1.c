#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
  int main() {
    int fd = open("example.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    const char* text = "Hello, World!\n";
    ssize_t bytes_written = write(fd, text, strlen(text));
    if (bytes_written == -1) {
        perror("write");
        return 1;
    }
    
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    
    fd = open("example.txt", O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }
    
    char buffer[1024];
    ssize_t bytes_read = read(fd, buffer, sizeof(buffer));
    if (bytes_read == -1) {
        perror("read");
        return 1;
    }
    printf("Contents of the file:\n%s", buffer);
    
    if (close(fd) == -1) {
        perror("close");
        return 1;
    }
    
    if (unlink("example.txt") == -1) {
        perror("unlink");
        return 1;
    }
    return 0;
}
