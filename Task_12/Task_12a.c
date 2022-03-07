/* Task12.a : To Simulate Sequential file allocation Strategy
Program: */

/*
#include<stdio.h>
#include<string.h>
void main()
{
int st[20],b[20],b1[20],ch,i,j,n,blocks[20][20],sz[20];
char F[20][20],S[20];
printf("\n Enter no. of Files ::");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n Enter file %d name ::",i+1);
scanf("%s",&F[i]);
printf("\n Enter file%d size(in kb)::",i+1);
scanf("%d",&sz[i]);
printf("\n Enter Starting block of %d::",i+1);
scanf("%d",&st[i]);
printf("\n Enter blocksize of File%d(in bytes)::",i+1);
scanf("%d",&b[i]);
}
for(i=0;i<n;i++)
b1[i]=(sz[i]*1024)/b[i];
for(i=0;i<n;i++)
{
for(j=0;j<b1[i];j++)
blocks[i][j]=st[i]+j;
}
do
{
printf("\nEnter the Filename ::");
scanf("%s",S);
for(i=0;i<n;i++)
{
if(strcmp(S,F[i])==0)
{
printf("\nFname\tStart\tNblocks\tBlocks\n");
printf("\n \n");
printf("\n%s\t%d\t%d\t",F[i],st[i],b1[i]);
for(j=0;j<b1[i];j++)
printf("%d->",blocks[i][j]);
}
}
printf("\n \n");
printf("\nDo U want to continue ::(Y:n)");
scanf("%d",&ch);
if(ch!=1)
break;
}while(1);
}  */


#include <stdio.h>
#include <stdlib.h>
void recurse(int files[]){
    int flag = 0, startBlock, len, j, k, ch;
    printf("Enter the starting block and the length of the files: ");
    scanf("%d%d", &startBlock, &len);
    for (j=startBlock; j<(startBlock+len); j++){
        if (files[j] == 0)
            flag++;
    }
    if(len == flag){
        for (int k=startBlock; k<(startBlock+len); k++){
            if (files[k] == 0){
                files[k] = 1;
                printf("%d\t%d\n", k, files[k]);
            }
        }
        if (k != (startBlock+len-1))
            printf("The file is allocated to the disk\n");
    }
    else
        printf("The file is not allocated to the disk\n");
    printf("Do you want to enter more files?\n");
    printf("Press 1 for YES, 0 for NO: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse(files);
    else
        exit(0);
    return;
}
int main()
{
int files[50];
for(int i=0;i<50;i++)
files[i]=0;
printf("Files Allocated are :\n");
recurse(files);

return 0;
}


