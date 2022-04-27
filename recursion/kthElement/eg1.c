//technique 1:- all the elements before the desired index must be less than the element at that index and all the must be greater than after that 
#include<stdio.h>
int main()
{
int x[10],i,g,j,k,pivot,swaps;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
printf("Enter the number of smallest element : ");
scanf("%d",&k);
if(k<=0 || k>10) 
{
printf("Invalid element number");
return 0;
}
pivot=k-1;
while(1)
{
swaps=0;
for(i=0;i<pivot;i++)
{
if(x[i]>x[pivot])
{
swaps=1;
g=x[i];
x[i]=x[pivot];
x[pivot]=g;
}
}
for(j=9;j>pivot;j--)
{
if(x[j]<x[pivot])
{
swaps=1;
g=x[j];
x[j]=x[pivot];
x[pivot]=g;
}
}
if(swaps==0) break;
}
if(k==1)
{
printf("%dst smallest element is : %d",k,x[pivot]);
}
else if(k==2)
{
printf("%dnd smallest element is : %d",k,x[pivot]);
}
else if(k==3)
{
printf("%drd smallest element is : %d",k,x[pivot]);
}
else printf("%dth smallest element is : %d",k,x[pivot]);
return 0;
}