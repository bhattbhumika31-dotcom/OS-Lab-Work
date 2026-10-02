// 5. Demonstrate a zombie process and observe using ps
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        printf("Child terminating...\n");
        exit(0);
    }
    else {
        printf("Parent: PID = %d\n", getpid());
        printf("Parent sleeping for 30 seconds...\n");

        sleep(30);
    }
    return 0;
}