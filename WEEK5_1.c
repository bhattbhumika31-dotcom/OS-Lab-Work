//Write a program to calculate sum of array in parent process and then check the calculated sum is prim eor not in child process.
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int arr[] = {13, 27, 19, 15, 26};
    int n = 5;
    int sum = 0;
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (pid > 0) 
    {
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        printf("Parent Process\n");
        printf("Sum of array = %d\n", sum);
        wait(NULL);
    }
    else           
    {
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }
        printf("Child Process\n");
        if (isPrime(sum))
            printf("%d is a Prime Number\n", sum);
        else
            printf("%d is Not a Prime Number\n", sum);
    }
    return 0;
}