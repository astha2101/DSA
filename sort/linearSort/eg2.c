#include<stdio.h>
#include<stdlib.h>
int main()
{
int req,*arr,i,e,f,g;
printf("Enter requirement :");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
for(e=0;e<req-1;e++)
{
for(f=e+1;f<req;f++)
{
if(arr[f]<arr[e])
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
}
for(i=0;i<req;i++) printf("%d\n",arr[i]);
free(arr);
return 0;
}