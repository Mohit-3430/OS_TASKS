/* Task 9 : To implement paging technique of memory management. */


#include<stdio.h>
void main()
{
int np,ps,pt[20],nf,la,pn,index,pa,i,j;
printf("\n enter number of pages:");
scanf("%d",&np);
printf("\n enter page size");
scanf("%d",&ps);
printf("\n enter page table");
for(i=0;i<np;i++)
scanf("%d",&pt[i]);
printf("\n enter number of frames:");
scanf("%d",&nf);
printf("\n enter logical address");
scanf("%d",&la);
pn=la/ps;
index=la%ps;
pa=(pt[pn]+ps)+index;
printf("\n physical address is %d",pa);
}
