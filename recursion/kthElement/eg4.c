#include<stdio.h>
int main()
{
int x[10],i,e,f,g,m,ub,k;
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
ub=9;
for(m=k-1;m>=0;m--)
{
for(e=0,f=1;e<ub;e++,f++)
{
if(x[f]>x[e])
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
}
ub--;
}
if(k==1)
{
printf("%dst smallest element is : %d",k,x[10-k]);
}
else if(k==2)
{
printf("%dnd smallest element is : %d",k,x[10-k]);
}
else if(k==3)
{
printf("%drd smallest element is : %d",k,x[10-k]);
}
else printf("%dth smallest element is : %d",k,x[10-k]);
return 0;
}