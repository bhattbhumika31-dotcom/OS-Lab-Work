// 5. Print the value returned by fork() in both processes
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else {
        printf("PID = %d, fork() returned = %d\n",
               getpid(), pid);
    }

    return 0;
}