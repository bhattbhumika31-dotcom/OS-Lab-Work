//orphan process 
#include <stdio.h>
#include <unistd.h>
int main()
{
    int n;
    printf("Enter number");
    scanf("%d",&n);
    pid_t pid = fork();
    if(pid==0)
    {
        //adopeted by init process so process id of parent will be 1
        printf("Child process: %d and Parent process id: %d \n",getpid(),getppid());
        sleep(10);
        printf("Child process: %d and Parent process id: %d \n",getpid(),getppid());    
    }
    else
    {
        printf("Parent process existing");
    }
    return 0;
}
