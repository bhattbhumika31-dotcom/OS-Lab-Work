// . Child exits with status 10 and parent reads status using wait()
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        printf("Child: Exiting with status 10\n");
        exit(10);
    } 
    else {
        int status;

        wait(&status);

        if (WIFEXITED(status)) {
            printf("Parent: Child exited normally\n");
            printf("Parent: Exit status = %d\n",
                   WEXITSTATUS(status));
        }
    }
    return 0;
}