// linear sort
#include<stdio.h>
int main()
{
int x[10],i,e,f,g,k;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
printf("Enter the number of the nth smallest element : ");
scanf("%d",&k);
if(k<=0 || k>10)
{
printf("Invalid element number ");
return 0;
}
for(e=0;e<k;e++)
{
for(f=e+1;f<=9;f++)
{
if(x[f]<x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
}
if(k==1)
{
printf("%dst smallest element is : %d",k,x[k-1]);
}
else if(k==2)
{
printf("%dnd smallest element is : %d",k,x[k-1]);
}
else if(k==3)
{
printf("%drd smallest element is : %d",k,x[k-1]);
}
else printf("%dth smallest element is : %d",k,x[k-1]);
return 0;
}