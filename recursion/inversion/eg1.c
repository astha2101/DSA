// find the total count of inversions in an array
#include<stdio.h>
#include<stdlib.h>
int merge(int *x,int lb,int mid,int ub,int *temp)
{
int i1,i2,i3,count;
count=0;
i1=lb;
i2=mid+1;
i3=lb;
while(i1<=mid && i2<=ub)
{
if(x[i1]<x[i2])
{
temp[i3]=x[i1];
i1++;
}
else
{
temp[i3]=x[i2];
count=count+(mid-i1)+1;
i2++;
}
i3++;
}
while(i1<=mid)
{
temp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub)
{
temp[i3]=x[i2];
i2++;
i3++;
}
i3=lb;
while(i3<=ub)
{
x[i3]=temp[i3];
i3++;
}
return count;
}
int mergeSort(int *x,int lb,int ub,int *temp)
{
int mid,count=0;
if(lb<ub)
{
mid=(ub+lb)/2;
count=count+mergeSort(x,lb,mid,temp);
count=count+mergeSort(x,mid+1,ub,temp);
count=count+merge(x,lb,mid,ub,temp);
}
return count;
}
int inversionCount(int *arr,int size)
{
int *temp,count;
temp=(int *)malloc(sizeof(int)*size);
count=mergeSort(arr,0,size-1,temp);
free(temp);
return count;
}
int main()
{
int arr[10],i;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
printf("Inversion count : %d",inversionCount(arr,10));
return 0;
}