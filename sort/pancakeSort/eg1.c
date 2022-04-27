#include<stdio.h>
void reverse(int *arr,int lb,int ub)
{
int i,j,g;
i=lb;
j=ub;
while(i<=j)
{
g=arr[i];
arr[i]=arr[j];
arr[j]=g;
i++;
j--;
}
}
int main()
{
int arr[10];
int size,i,index,j,max,m;
size=10;
for(i=0;i<size;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
for(m=9;m>=0;m--)
{
i=0;
index=0;
max=arr[i];
for(j=i+1;j<=m;j++)
{
if(arr[j]>max)
{
max=arr[j];
index=j;
}
}
if(index!=m)
{
reverse(arr,0,index);
reverse(arr,0,m);
}
}
for(i=0;i<size;i++)
{
printf("%d\n",arr[i]);
}
return 0;
}