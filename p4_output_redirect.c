#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child: redirect standard input to a file
        close(STDIN_FILENO);
        open("./p4.input", O_RDONLY);

        // now exec "wc"...
        char *myargs[2];
        myargs[0] = strdup("wc");     // program: "wc"
        myargs[1] = NULL;             // no argument, will read from stdin
        execvp(myargs[0], myargs);    // runs word count
    } else {
        // parent goes down this path (main)
        int wc = wait(NULL);
    }
    return 0;
}