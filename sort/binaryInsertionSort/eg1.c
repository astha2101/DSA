#include<stdio.h>
int binarySearch(int *arr,int num,int lb,int ub)
{
int si,ei,mid;
si=lb;
ei=ub;
while(si<=ei)
{
mid=si+(ei-si)/2;
if(num==arr[mid]) return mid;
if(num<arr[mid]) ei=mid-1;
else si=mid+1;
}
return si;
}
int main()
{
int arr[10],i,j,pos,num;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
for(i=1;i<=9;i++)
{
j=i-1;
num=arr[i];
pos=binarySearch(arr,num,0,j);
while(j>=pos)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=num;
}
for(i=0;i<=9;i++) printf("%d\n",arr[i]);
return 0;
}