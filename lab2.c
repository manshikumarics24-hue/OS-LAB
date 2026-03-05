#include <stdio.h>

#define max 10

struct process
{
    int at;  
    int bt;   
    int wt;  
    int tat;  
    int ct;   
};

void sortProcesses(struct process p[], int n)
{
    int i, j;
    struct process temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-1-i; j++)
        {
            if(p[j].at > p[j+1].at)
            {
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void FCFS(struct process p[], int n)
{
    int t = 0, i;
    float awt = 0.0, atat = 0.0;

    sortProcesses(p, n);

    for(i = 0; i < n; i++)
    {
        if(t < p[i].at)
            t = p[i].at;

        p[i].wt = t - p[i].at;
        p[i].ct = t + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;

        t = p[i].ct;
    }

    printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "WT", "TAT");

    for(i = 0; i < n; i++)
    {
        printf("%-5d%-5d%-5d%-5d%-5d%-5d\n", i, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
        awt += p[i].wt;
        atat += p[i].tat;
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time = %.2f\n", awt);
    printf("Average Turnaround Time = %.2f\n", atat);
}

int main()
{
    int n, i;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &p[i].at);

        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    FCFS(p, n);

    return 0;
}