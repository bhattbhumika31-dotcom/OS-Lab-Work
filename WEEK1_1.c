//1. Parent prints even numbers and child prints odd numbers from 1 to 20
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        return 1;
    }
    if (pid == 0) {
        for (int i = 1; i <= 20; i += 2) {
            printf("Child: %d\n", i);
        }
    } else {
        for (int i = 2; i <= 20; i += 2) {
            printf("Parent: %d\n", i);
        }
        wait(NULL);
    }
    return 0;
}