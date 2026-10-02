// Write a C program using fork() to create a child process. The child process should generate
//  and display the Fibonacci series up to n terms, while the parent process should find and display 
//  all Armstrong numbers from 0 to n. The parent process should wait for
//  the child process to complete using wait()
 #include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void fibonacci(int n) {
    int a = 0, b = 1, c;

    printf("Child: Fibonacci Series:\n");

    for (int i = 1; i <= n; i++) {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");
}

int armstrong(int n) {
    int original = n;
    int sum = 0;
    int digit;

    while (n != 0) {
        digit = n % 10;
        sum = sum + (digit * digit * digit);
        n = n / 10;
    }

    return sum == original;
}

int main() {
    int n;

    printf("Enter n: ");
    scanf("%d", &n);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    }
    else if (pid == 0) {
        fibonacci(n);
    }
    else {
        printf("Parent: Armstrong numbers up to %d:\n", n);

        for (int i = 0; i <= n; i++) {
            if (armstrong(i)) {
                printf("%d ", i);
            }
        }

        printf("\n");
        wait(NULL);
    }

    return 0;
}