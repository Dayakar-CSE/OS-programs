#include<stdio.h>
#include<conio.h>
int main()
{
int bt[20],p[20],wt[20],tat[20],pri[20],i,j,k,n,total=0,pos,temp;
float avg_wt,avg_tat;
clrscr();
printf("Enter the process");
scanf("%d",&n);
printf("\n Enter the brust time:\n");
for(i=0;i<n;i++)
{
printf("p%d",i+1);
scanf("%d",&bt[i]);
p[i]=i+1;
}
printf("Enter priority of proces");
for(i=0;i<n;i++)
{
p[i]=i;
printf("p%d",i+1);
scanf("%d",&pri[i]);
}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(pri[i]>pri[k])
{
temp=p[i];
p[i]=p[k];
p[k]=temp;

temp=bt[i];
bt[i]=bt[k];
bt[k]=temp;
temp=pri[i];
 pri[i]=pri[k];
 pri[k]=temp;
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
printf("\n Process\t brust time\t priority\t waiting time\t turnarounf time\t");
for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
total+=tat[i];
printf("\n p%d\t\t %d\t\t %d\t\t %d\t\t\t %d",p[i],bt[i],pri[i],wt[i],tat[i]);
}
avg_tat=(float) total/n;
printf("\n\n Average waiting time =%f",avg_wt);
printf("\n Average turnaround time=%f\n",avg_tat);
getch();
return 0;

}
