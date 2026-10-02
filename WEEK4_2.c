//zombie processes
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("Child Process Running...");
        //child process chalke khtm but no report to parent to process table se vo hatega nahi
    }
    else
    {
        sleep(45);//childing want to report but parent is sleeping
        wait(NULL);//aatma ko shanti(child will wait until you wake up)
        printf("Papa milgaye");
    }
    return 0;
}