// 4. Demonstrate an orphan process and record child's PPID before and after parent terminates
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        printf("Child: PID = %d\n", getpid());
        printf("Child: PPID before parent terminates = %d\n",
               getppid());
        sleep(5);
        printf("Child: PPID after parent terminates = %d\n",
               getppid());
    }
    else {
        printf("Parent: PID = %d\n", getpid());
        printf("Parent terminating...\n");
        exit(0);
    }
    return 0;
}