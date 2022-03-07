#include <stdio.h>
#include <stdlib.h>
int files[50], indexBlock[50], indBlock, n;
void recurse1();
void recurse2();
void recurse1(){
    printf("Enter the index block: ");
    scanf("%d", &indBlock);
    if (files[indBlock] != 1){
        printf("Enter the number of blocks and the number of files needed for the index %d on the disk: ", indBlock);
        scanf("%d", &n);
    }
    else{
        printf("%d is already allocated\n", indBlock);
        recurse1();
    }
    recurse2();
}
void recurse2(){
    int ch;
    int flag = 0;
    for (int i=0; i<n; i++){
        scanf("%d", &indexBlock[i]);
        if (files[indexBlock[i]] == 0)
            flag++;
    }
    if (flag == n){
        for (int j=0; j<n; j++){
            files[indexBlock[j]] = 1;
        }
        printf("Allocated\n");
        printf("File Indexed\n");
        for (int k=0; k<n; k++){
            printf("%d ------> %d : %d\n", indBlock, indexBlock[k], files[indexBlock[k]]);
        }
    }
    else{
        printf("File in the index is already allocated\n");
        printf("Enter another indexed file\n");
        recurse2();
    }
    printf("Do you want to enter more files?\n");
    printf("Enter 1 for Yes, Enter 0 for No: ");
    scanf("%d", &ch);
    if (ch == 1)
        recurse1();
    else
        exit(0);
    return;
}
int main()
{
    for(int i=0;i<50;i++)
        files[i]=0;
    recurse1();
    return 0;
}



/*
#include<stdio.h>
#include<string.h>
int n;
void main()
{
int b[20],b1[20],i,j,blocks[20][20],sz[20];
char F[20][20],S[20],ch;
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
printf("\n\nEnter blocks for file%d",i+1);
for(j=0;j<b1[i];j++)
{
printf("\n Enter the %dblock ::",j+1);
scanf("%d",&blocks[i][j]);
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
printf("\n
\n");
printf("\n%s\t%d\t%d\t%d\t",F[i],sz[i],b[i],b1[i]);
for(j=0;j<b1[i];j++)
printf("%d->",blocks[i][j]);
}
}
printf("\n
\n");
printf("\nDo U want to continue ::(Y:n)");
scanf("%d",&ch);
}while(ch!=0);
}*/
