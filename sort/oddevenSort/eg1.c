#include<stdio.h>
int main()
{
int arr[10],i,g,oddIndex,evenIndex,swap;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
while(1)
{
swap=0;
for(oddIndex=1;oddIndex<=9;oddIndex+=2)
{
if(arr[oddIndex+1]<arr[oddIndex])
{
swap=1;
g=arr[oddIndex];
arr[oddIndex]=arr[oddIndex+1];
arr[oddIndex+1]=g;
}
}
for(evenIndex=0;evenIndex<=9;evenIndex+=2)
{
if(arr[evenIndex+1]<arr[evenIndex])
{
swap=1;
g=arr[evenIndex];
arr[evenIndex]=arr[evenIndex+1];
arr[evenIndex+1]=g;
}
}
if(swap==0) break;
}
for(i=0;i<=9;i++) printf("%d\n",arr[i]);
return 0;
}