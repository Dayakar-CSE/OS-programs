# include<stdio.h>
#include<conio.h>
int main()
{
int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
float avg_wt,avg_tat;
clrscr();
printf("enter number of process");
scanf("%d",&n);
printf("\n enter burst time");
for(i=0;i<n;i++)
{
printf("p%d:",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}
wt[0]=0;
for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
total+=wt[i];
}

avg_wt=(float)total/n;
total=0;
printf("\n process \t Burst Time \t waiting Time \t Turnaround Time");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\n p%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
}
avg_tat=(float)total/n;
printf("\n\n Average waiting Time=%f",avg_wt);
printf("\n Average Turnaround Time=%f\n",avg_tat);
return 0;
}

