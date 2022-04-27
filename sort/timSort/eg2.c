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
free(tmp);
}
int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}
int main()
{
int  *arr,size,n,i,lb,ub,mid;
int portionSize=63;
FILE *f;
f=fopen("data.d","rb");
fseek(f,0,2);
size=ftell(f);
n=size/4;
if(n<portionSize) portionSize=n/2;
arr=(int *)malloc(sizeof(int)*n);
fseek(f,0,0);
for(i=0;i<n;i++)
{
fread(&arr[i],sizeof(int),1,f);
}
fclose(f);
i=0;
while(i<n)
{
lb=i;
if((n-i)<portionSize) ub=lb+(n-i);
else ub=lb+portionSize;
quickSort(arr,lb,ub);
i=ub+1;
}
i=portionSize;
while(1)
{
lb=0;
mid=i;
ub=mid+1+portionSize;
if(ub>n-1) ub=n-1;
//printf("%d %d %d\n",lb,mid,ub);
merge(arr,lb,mid,ub);
if(ub==(n-1)) break;
i=ub;
}
for(i=0;i<n;i++) printf("%d ",arr[i]);
free(arr);
return 0;
}