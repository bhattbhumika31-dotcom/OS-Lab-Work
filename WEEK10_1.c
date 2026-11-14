//Shortest Job First
#include <stdio.h>
int main(){
    int n,i,j;
    int bt[20],pid[20],wt[20],tat[20];
    float avgWT=0,avgTAT=0;
    printf("Enter the number of process");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        pid[i]=i+1;
        printf("Enter burst time for %d",i+1);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
        if(bt[i]>bt[j]){
            int temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;

            temp=pid[i];
            pid[i]=pid[j];
            pid[j]=temp;
            }
        }
    }
    wt[0] = 0;
    for(i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        avgWT=avgWT+wt[i];
        avgTAT=avgTAT+tat[i];
    }
    avgWT=avgWT/n;
    avgTAT=avgTAT/n;
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0;i<n;i++){
        printf("%d\t%d\t\t%d\t\t%d\n",pid[i],bt[i],wt[i],tat[i]);
    }
    printf("Average Waiting Time=%f\n",avgWT);
    printf("Average Turnaround Time=%f\n",avgTAT);
    return 0;
}