#include <stdio.h>
struct PCB{
    int burst, pid, wait, turnaround;
};
void pline(int);
void main()
{
    struct PCB p[10], temp;
    int i, n, j=1, sum=0, w_total=0,t_total=0;
    float w_avg=0.0, t_avg=0.0;
    printf("SJF algorithm\n");
    printf("Enter the total number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the burst time of process %d:\n",i+1);
        scanf("%d",&p[i].burst);
        p[i].pid=i+1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(p[j].burst>p[j+1].burst)
            {
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        p[i].wait = sum;
        sum = sum + p[i].burst;
        p[i].turnaround = sum;
    }
    pline(35);
    printf("PID\tBurst\tWait\tTurnaround");
    pline(35);
    for(i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].burst,p[i].wait,p[i].turnaround);
        w_total+=p[i].wait;
        t_total+=p[i].turnaround;
    }
    w_avg = w_total/(float)n;
    t_avg = t_total/(float)n;
    printf("\nTotal Waiting Time : %d",w_total);
    printf("\nAverage Waiting Time : %.3f", w_avg);
    printf("\nTotal Turnaround Time : %d ",t_total);
    printf("\nAverage Turnaround Time : %.3f",t_avg);
}
void pline(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("-");
    }
    printf("\n");
}
