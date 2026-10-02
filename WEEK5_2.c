//wap in c language to create input.txt in parent process and write your name univeristy roll no and class roll no in it and then read same file in child process and print the content 
//parent child ko btayega this is the file name  
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    if (pid > 0)
    {

        FILE *fp;
        fp = fopen("input.txt", "w");
        if (fp == NULL)
        {
            printf("File could not be created\n");
            return 1;
        }
        fprintf(fp, "Name: Bhumika Bhatt\n");
        fprintf(fp, "University Roll No: 2025817\n");
        fprintf(fp, "Class Roll No: 16\n");
        fclose(fp);
        printf("Parent: Data written successfully to input.txt\n");
        wait(NULL);
    }
    else
    {
        FILE *fp;
        char ch;
        fp = fopen("input.txt", "r");
        if (fp == NULL)
        {
            printf("File could not be opened\n");
            return 1;
        }
        printf("\nChild: Content of input.txt\n");
        while ((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(fp);
    }
    return 0;
}