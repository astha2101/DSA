#include<stdio.h>
int main()
{
int arr[10],i,m,lb,ub,e,f,g,swap;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
lb=0;
ub=9;
for(m=9;m>=0;m--)
{
swap=0;
for(e=lb,f=e+1;e<ub;e++,f++)
{
if(arr[f]<arr[e])
{
swap=1;
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
ub--;
for(e=ub,f=e-1;e>lb;e--,f--)
{
if(arr[f]>arr[e])
{
swap=1;
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
lb++;
if(swap==0) break;
}
for(i=0;i<=9;i++) printf("%d\n",arr[i]);
return 0;
}