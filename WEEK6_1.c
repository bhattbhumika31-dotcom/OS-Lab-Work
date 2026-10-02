// wap to open a file in child prcess then you have to write all even numbers upto n and then pass the name of file through pipe to parent process and then read and print the content of the file
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int pipefd[2];
    int n;
    
    char receivedFile[20];
    printf("Enter n: ");
    scanf("%d", &n);
    pipe(pipefd);
    pid = fork();
    if (pid == 0)
    {
    
        FILE *fp = fopen(filename, "w");
        for (int i = 2; i <= n; i += 2)
        {
            fprintf(fp, "%d ", i)\\

        }

        fclose(fp);

     
        close(pipefd[0]);
        write(pipefd[1], filename, sizeof(filename));
        close(pipefd[1]);
    }
    else
    {
        

        wait(NULL);

        close(pipefd[1]);

        read(pipefd[0], receivedFile, sizeof(receivedFile));
        close(pipefd[0]);

        FILE *fp = fopen(receivedFile, "r");

        char ch;

        printf("\nEven numbers are: ");

        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }

        fclose(fp);
    }

    return 0;
}