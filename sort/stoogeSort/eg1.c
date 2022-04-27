#include<stdio.h>
void stoogeSort(int *arr,int lb,int ub)
{
int n,g,p;
n=ub-lb+1;
if(arr[lb]>arr[ub])
{
g=arr[lb];
arr[lb]=arr[ub];
arr[ub]=g;
}
if(n>2)
{
p=n/3;
stoogeSort(arr,lb,ub-p);
stoogeSort(arr,lb+p,ub);
stoogeSort(arr,lb,ub-p);
}
}
int main()
{
int arr[10],i;
for(i=0;i<=9;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
stoogeSort(arr,0,9);
for(i=0;i<=9;i++) printf("%d\n",arr[i]);
return 0;
}