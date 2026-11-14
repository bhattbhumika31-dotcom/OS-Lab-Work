//FIRST COME FIRST SERVE
#include <stdio.h>
int main(){
    int n,i;
    int bt[20],wt[20],tat[20];
    float TWT=0.0;
    float TTAT=0.0;
    printf("Enter number of processes: ");
    scanf("%d",&n);
    printf("Enter burst time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("P%d",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0]=0;//fcfs mai pehla process directly cpu execute krega thats why wt=0;
    for(i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];
    }
    for(i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
        TWT=TWT+wt[i];
        TTAT=TTAT+tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    }
    printf("\nAverage waiting time: %.2f",TWT/n);
    printf("\nAverage turnaround time: %.2f",TTAT/n);
    return 0;
}