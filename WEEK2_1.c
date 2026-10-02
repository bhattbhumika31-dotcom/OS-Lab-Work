// Write a C program using fork() to create a child process. The child process should check whether the 
// entered number is prime or not, while the parent process should calculate and display the factorial of 
// the entered number. The parent should wait for the child process to complete using wait()
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        int flag = 1;

        if (n <= 1) {
            flag = 0;
        }

        for (int i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                flag = 0;
                break;
            }
        }

        if (flag)
            printf("Child: %d is a Prime number\n", n);
        else
            printf("Child: %d is not a Prime number\n", n);
    }
    else {
        unsigned long long fact = 1;

        for (int i = 1; i <= n; i++) {
            fact = fact * i;
        }

        printf("Parent: Factorial of %d = %llu\n", n, fact);

        wait(NULL);
    }

    return 0;
}