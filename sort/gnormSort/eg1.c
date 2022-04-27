#include<stdio.h>
int main()
{
int arr[10],i,j,g;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
for(i=0;i<=9;i++)
{
for(j=i;j>0;j--)
{
if(arr[j]<arr[j-1])
{
g=arr[j];
arr[j]=arr[j-1];
arr[j-1]=g;
}
}
}
for(i=0;i<=9;i++)
{
printf("%d\n",arr[i]);
}
return 0;
}