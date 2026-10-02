//write a c program to demonstarte zombie and orphan process
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main() {
    pid_t pid = fork();
    if (pid == 0) {
        printf("Child process is running\n");
        printf("Child process is exiting\n");
    }
    else {
        printf("Parent process is sleeping\n");
        sleep(10);
        printf("Parent process is exiting\n");
    }
    return 0;
}
