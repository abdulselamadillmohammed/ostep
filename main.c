#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main (int argc, char *argv[]){
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU); // Open (or create) file for writing
    assert (fd > -1); // Checking mechanism
    int rc = write(fd, "hello world\n", 13); // Write 13 bytes into the file
    close(fd); // No longer able to write
    return 0;
}