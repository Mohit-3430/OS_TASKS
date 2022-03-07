/*Task 3a. 

To Simulate the Round Robin CPU Scheduling algorithm.*/

#include<stdio.h>
int temp=0;
struct roundrobin
{
char pname[10];
int burst,time;
}
p[10];
void main()
{
int i,n,full,q,wait[10],tat[10],time1=0;
float avg=0;
printf("enter no of processes and timeslot\t:");
scanf("%d %d",&n,&q);
for(i=0;i<n;i++)
{
printf("\n enter the process%d, name, bursttime ",i+1);
scanf("%s %d",p[i].pname,&p[i].burst);
p[i].time=p[i].burst;
}
full=n;
while(full)
{
for(i=0;i<n;i++)
{
if(p[i].burst>=q)
{
p[i].burst=p[i].burst-q;
time1=time1+q;
}
else if(p[i].burst!=0)
{
time1=time1+p[i].burst;
p[i].burst=0;
}
else
continue;
if(p[i].burst==0)
{
full=full-1;
tat[i]=time1;
}
}
}
for(i=0;i<n;i++)
wait[i]=tat[i]-p[i].time;
printf("\n pname tat wait");
for(i=0;i<n;i++)
{
printf("\n %3s %3d %3d",p[i].pname,wait[i],tat[i]);
avg=avg+wait[i];
}

printf("\n avg wait time is %f\n",avg);
avg=avg/n;
printf("average turn around time is %f\n",avg);
}

