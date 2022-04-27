#include<stdio.h>
int main()
{
int arr[10];
int i,j,e,f,g;
for(i=0;i<10;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
for(e=0;e<9;e++)
{
for(f=e+1;f<10;f++)
{
if(arr[f]<arr[e])
{
g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
}
for(i=0;i<10;i++) printf("%d\n",arr[i]);
return 0;
}
