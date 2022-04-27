#include<stdio.h>
#include<stdlib.h>
void linearSort(int *arr,int n)
{
int e,f,g;
for(e=0;e<n-1;e++)
{
for(f=e+1;f<n;f++)
{
if(arr[f]<arr[e])
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
}
}
int main()
{
int req,*arr,i;
printf("Enter requirement :");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
linearSort(arr,req);
for(i=0;i<req;i++) printf("%d\n",arr[i]);
return 0;
}