#include<stdio.h>
#include<malloc.h>
void mergeSort(int *arr,int lowerBound,int upperBound)
{
int top1,top2,i1,i2,i3,i,lb1,ub1,lb2,ub2,stackSize,a,b,mid,sizeOfList;
int *tmp,**stack1,**stack2;
sizeOfList=(upperBound-lowerBound)+1;
stackSize=sizeOfList;
top1=stackSize;
top2=stackSize;
stack1=(int **)malloc(sizeof(int)*stackSize);
stack2=(int **)malloc(sizeof(int)*stackSize);
for(int i=0;i<stackSize;i++)
{
stack1[i]=(int *)malloc(sizeof(int)*2);
stack2[i]=(int *)malloc(sizeof(int)*2);
}
tmp=(int *)malloc(sizeof(int)*sizeOfList);
top1--;
stack1[top1][0]=lowerBound;
stack1[top1][1]=upperBound;
while(top1!=stackSize)
{
a=stack1[top1][0];
b=stack1[top1][1];
top1++;
top2--;
stack2[top2][0]=a;
stack2[top2][1]=b;
mid=(a+b)/2;
if(a<mid)
{
top1--;
stack1[top1][0]=a;
stack1[top1][1]=mid;
}
if(mid+1<b)
{
top1--;
stack1[top1][0]=mid+1;
stack1[top1][1]=b;
}
}
while(top2!=stackSize)
{
a=stack2[top2][0];
b=stack2[top2][1];
top2++;
mid=(a+b)/2;
lb1=a;
ub1=mid;
lb2=mid+1;
ub2=b;
i1=lb1;
i2=lb2;
i3=lb1;
while(i1<=ub1 && i2<=ub2)
{
if(arr[i1]<arr[i2])
{
tmp[i3]=arr[i1];
i1++;
}
else
{
tmp[i3]=arr[i2];
i2++;
}
i3++;
}
while(i1<=ub1)
{
tmp[i3]=arr[i1];
i1++;
i3++;
}
while(i2<=ub2)
{
tmp[i3]=arr[i2];
i3++;
i2++;
}
i=lb1;
while(i<=ub2)
{
arr[i]=tmp[i];
i++;
}
}
free(tmp);
for(i=0;i<stackSize;i++)
{
free(stack1[i]);
free(stack2[i]);
}
free(stack1);
free(stack2);
}
int main()
{
int arr[10];
for(int i=0;i<10;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
mergeSort(arr,0,9);
for(int i=0;i<10;i++) printf("%d\n",arr[i]);
return 0;
}