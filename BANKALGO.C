#include<stdio.h>
#include<conio.h>
 int max[10][10],alloc[10][10],need[10][10],avail[10],i,j,p,r,finish[10] = {0},flag=0;
 void main()
 {
  clrscr();
  printf("\n SIMULATION OF DEADLOCK PREVENTION \n");
  printf(" enter no. of process,resources \n");
  scanf("%d%d",&p,&r);
  printf("\n enter allocation matrix \n");
  for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&alloc[i][j]);
 printf("\n enter max matrix \n ");
  for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      scanf("%d",&max[i][j]);
 printf("\n enter available matrix ");
 for(i=0;i<r;i++)
    scanf("%d",&avail[i]);
 for(i=0;i<p;i++)
    for(j=0;j<r;j++)
      need[i][j] = max[i][j]-alloc[i][j];
  fun();
  if(flag==0)
  {
   if(finish[i]!= 1)
   {
    printf("\n failing : mutual exclusion ");
    for(j=0;j<r;j++)
      if(avail[j] < need[i][j])
	    avail[j] = need[i][j];
    fun();
    printf("\n by allocating required resources to process %d deadlock is prevented ");
    printf("\n lack of prevention ");
    for(j=0;j<r;j++)
    {
     if(avail[j] < need[i][j])
	avail[j] = need[i][j];
      alloc[i][j]= 0;
     }
     fun();
     printf("\n  deadlock is prevented by allocating needed resources ");
     printf("\n failing : hold and wait condition ");
     for(j=0;j<r;j++)
      if(avail[j] < need[i][j])
	avail[j] = need[i][j];
     fun();
     printf("\n AVOIDING ANY ONE OF THE CONDITION ,U CAN PREVENT DEADLOCK");
     }
    }
    getch();
  }
  fun()
  {
   while(1)
   {
    for(flag=0,i=0;i<p;i++)
    {
     if(finish[i] == 0)
     {
      for(j=0;j<r;j++)
      {
       if(need[i][j] <= avail[j])
	 continue;
       else
	 break;
      }
      if(j==r)
      {
       for(j=0;j<r;j++)
	avail[j] += alloc[i][j];
	flag=1;
	finish[i] = 1;
       }
      }
    }
  }
 }

