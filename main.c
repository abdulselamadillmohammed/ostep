#include <stdio.h>
#include <unistd.h>
#include <assert.h>
#include <fcntl.h>
#include <sys/types.h>

int main (int argc, char *argv[]){
    int fd = open("/tmp/file", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU); // Open area in memory to write to
    assert (fd > -1); // Checking if memory aquired to write 
    int rc = write(fd, "hello world\n", 13); // Write to aquired space
    close(fd); // No longer able to write
    return 0;
}