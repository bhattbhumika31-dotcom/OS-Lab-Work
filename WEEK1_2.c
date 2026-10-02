// 2. Create three child processes. Each child prints PID, PPID and child number
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    for (int i = 1; i <= 3; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            return 1;
        }
        if (pid == 0) {
            printf("Child %d: PID = %d, PPID = %d\n",
                   i, getpid(), getppid());
            return 0;
        }
    }
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }

    return 0;
}