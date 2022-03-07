/* 12c) To implement linked file allocation method.

#include<stdio.h>
#include<string.h>
int n;
void main()
{
int b[20],b1[20],i,j,blocks[20][20],sz[20];
char F[20][20],S[20],ch;
int sb[20],eb[20],x;
printf("\n Enter no. of Files ::");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n Enter file %d name ::",i+1);
scanf("%s",&F[i]);
printf("\n Enter file%d size(in kb)::",i+1);
scanf("%d",&sz[i]);
printf("\n Enter blocksize of File%d(in bytes)::",i+1);
scanf("%d",&b[i]);
}
for(i=0;i<n;i++)
{
b1[i]=(sz[i]*1024)/b[i];
printf("\n Enter Starting block of file%d::",i+1);
scanf("%d",&sb[i]);
printf("\n Enter Ending block of file%d::",i+1);
scanf("%d",&eb[i]);
printf("\nEnter blocks for file%d::\n",i+1);
for(j=0;j<b1[i]-2;)
{
printf("\n Enter the %dblock ::",j+1);
scanf("%d",&x);
if(x>sb[i]&&x<eb[i])
{
blocks[i][j]=x;
j++;
}
else
printf("\n Invalid block::");
}
}
do
{
printf("\nEnter the Filename ::");
scanf("%s",&S);
for(i=0;i<n;i++)
{
if(strcmp(F[i],S)==0)
{
printf("\nFname\tFsize\tBsize\tNblocks\tBlocks\n");

printf("\n%s\t%d\t%d\t%d\t",F[i],sz[i],b[i],b1[i]);
printf("%d->",sb[i]);
for(j=0;j<b1[i]-2;j++)
printf("%d->",blocks[i][j]);
printf("%d->",eb[i]);
}
}
printf("\nDo U want to continue (Y:n)::");
scanf("%d",&ch);
}while(ch!=0);
}  */



#include <stdio.h>
#include <stdlib.h>
void recursivePart(int pages[]){
    int st, len, k, c, j;
    printf("Enter the index of the starting block and its length: ");
    scanf("%d%d", &st, &len);
    k = len;
    if (pages[st] == 0){
        for (j = st; j < (st + k); j++){
            if (pages[j] == 0){
                pages[j] = 1;
                printf("%d------>%d\n", j, pages[j]);
            }
            else {
                printf("The block %d is already allocated \n", j);
                k++;
            }
        }
    }
    else
        printf("The block %d is already allocated \n", st);
    printf("Do you want to enter more files? \n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &c);
    if (c==1)
        recursivePart(pages);
    else
        exit(0);
    return;
}
int main(){
    int pages[50], p, a;
    for (int i = 0; i < 50; i++)
        pages[i] = 0;
    printf("Enter the number of blocks already allocated: ");
    scanf("%d", &p);
    printf("Enter the blocks already allocated: ");
    for (int i = 0; i < p; i++){
        scanf("%d", &a);
        pages[a] = 1;
    }
    recursivePart(pages);
    return 0;
}
 
