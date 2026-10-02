// 4. Two successive fork() calls
#include <stdio.h>
#include <unistd.h>

int main() {
    fork();
    fork();

    printf("Process PID = %d, PPID = %d\n", getpid(), getppid());

    return 0;
}