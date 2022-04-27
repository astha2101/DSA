// find kth smallest element
// Idea:- sort the array and then return the element at (k-1) index
// worst time complexity O(nlog(n)) (Merge Sort)

#include<stdio.h>
#include<stdlib.h>
void merge(int *x,int lb,int mid,int ub)
{
int *tmp,tmpSize,lb1,lb2,ub1,ub2,lb3,ub3,i1,i2,i3;
tmpSize=(ub-lb)+1;
tmp=(int *)malloc(sizeof(int)*tmpSize);
lb1=lb;
ub1=mid;
lb2=mid+1;
ub2=ub;
lb3=0;
ub3=tmpSize-1;
i1=lb1;
i2=lb2;
i3=lb3;
while(i1<=ub1 && i2<=ub2)
{
if(x[i1]<x[i2])
{
tmp[i3]=x[i1];
i1++;
}
else
{
tmp[i3]=x[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=x[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=x[i2];
i2++;
i3++;
}
i1=lb1;
i3=0;
while(i1<=ub2)
{
x[i1]=tmp[i3];
i1++;
i3++;
}
}
void mergeSort(int *x,int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergeSort(x,low,mid);
mergeSort(x,mid+1,high);
merge(x,low,mid,high);
}
}
int kthSmallest(int *arr,int k)
{
mergeSort(arr,0,9);
return arr[k-1];
}
int main()
{
int x[10],i,k;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
printf("Enter the index of the smallest element : ");
scanf("%d",&k);
if(k<0 || k>10) 
{
printf("Invalid Index\n");
return 0;
}
printf("%dth smallest element is %d",k,kthSmallest(x,k));
return 0;
}