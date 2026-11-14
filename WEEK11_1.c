//Priority Scheduling Algorithm

#include <stdio.h>

int main()
{
    int n, i, j;
    int bt[20], priority[20], pid[20];
    int wt[20], tat[20];
    int temp;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid[i] = i + 1;

        printf("Enter Burst Time and Priority for P%d: ", pid[i]);
        scanf("%d %d", &bt[i], &priority[i]);
    }

    // Sort processes according to priority
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(priority[i] > priority[j])
            {
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    wt[0] = 0;

    for(i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT = avgWT / n;
    avgTAT = avgTAT / n;

    printf("\nPID\tBT\tPriority\tWT\tTAT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t\t%d\t%d\n",
               pid[i], bt[i], priority[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avgWT);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT);

    return 0;
}