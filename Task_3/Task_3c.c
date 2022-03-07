/* 3c) To Simulate the First Come First Served CPU Scheduling algorithm.

Program: */

#include<stdio.h>
struct sa
{
char pro[10];
int bt,wt,tat,prior;
}p[10],temp;
void main()
{
int i,j,n,temp1=0;
float awt=0,atat=0;
printf("\n enter no of processes ");
scanf("%d",&n);
printf("\n enter process name, Priority and burst time ");
for(i=0;i<n;i++)
{
scanf("%s%d%d",p[i].pro,&p[i].bt,&p[i].prior);
}
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].prior>p[j].prior)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
for(i=0;i<n;i++)
{
p[i].wt=temp1;
p[i].tat=p[i].bt+p[i].wt;
temp1=temp1+p[i].bt;
}
for(i=0;i<n;i++)
{
awt=awt+p[i].wt;
atat=atat+p[i].tat;
}
printf("\n process /t bt /t prior /t wt /t tat");
awt=awt/n;
atat=atat/n;
for(i=0;i<n;i++)
{
printf("\n %5s %5d %5d %5d %5d",p[i].pro,p[i].prior,p[i].bt,p[i].wt,p[i].tat);
}
printf("\n average waiting time:%f",awt);
printf("\n average turn around time:%f",atat);
}
