#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main() {
    struct timeval start, end;
    int iterations = 1000000;

    gettimeofday(&start, NULL);
    for (int i = 0; i < iterations; i++) {
        gettimeofday(&end, NULL); // dummy system call
    }
    gettimeofday(&end, NULL);

    double elapsed = (end.tv_sec - start.tv_sec) * 1e6;
    elapsed += (end.tv_usec - start.tv_usec);
    printf("Average time per gettimeofday(): %.2f microseconds\n", elapsed / iterations);

    return 0;
}
