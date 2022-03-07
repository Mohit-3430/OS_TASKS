/* 3b) 
To Simulate the Shortest Job First(SJF) CPU Scheduling Program: */

#include<stdio.h>
struct sa
{
char pro[10];
int bt,wt,tat;
}p[10],temp[10];
void main()
{
int i,j,n,temp1=0;
float awt=0,atat=0;
printf("\n enter the no of processes ");
scanf("%d",&n);
printf("\n enter the process name and bursttime :");
for(i=0;i<n;i++)
{
scanf("%s %d",p[i].pro,&p[i].bt);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].bt>p[j].bt)
{
temp[i]=p[i];
p[i]=p[j];
p[j]=temp[i];
}
}
}
for(i=0;i<n;i++)
{
p[i].wt=temp1;
p[i].tat=p[i].bt+p[i].wt;
temp1=p[i].bt+temp1;
}
for(i=0;i<n;i++)
{
awt=awt+p[i].wt;
atat=atat+p[i].tat;
}
awt=awt/n;
atat=atat/n;
printf("Process \t bt \t wt \t tat");
for(i=0;i<n;i++)
{
printf("\n %5s \t %5d \t %5d \t %5d",p[i].pro,p[i].bt,p[i].wt,p[i].tat);
}
printf("\n Average waiting time:%f\n",awt);
printf("\n Average turn around time:%f\n",atat);
}

