// 3. Child prints 1 to 5, parent waits using wait()
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        printf("Child Process:\n");

        for (int i = 1; i <= 5; i++) {
            printf("%d\n", i);
        }
    }
    else {
        wait(NULL);
        printf("Parent Process: Child completed\n");
    }

    return 0;
}