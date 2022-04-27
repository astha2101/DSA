#include<stdio.h>
int arr[900];
int tmp[100];
void combinations(int *arr,int *base,int *size,int *tmp)
{
int i,j,n,start;
if(*base==0)
{
*size=0;
for(i=0;i<=9;i++)
{
tmp[i]=i;
*size++;
}
}
*base=*base/10;
combinations(arr,base,size);
if(*base==10) start=0;
else start=1;
n=*size;
*size=0;
for(i=start;i<=9;i++)
{
for(j=0;j<n;j++)
{
arr[*size]=i*10+tmp[j];
*size++;
}
}
}
int main()
{
int base,size,i;
base=100;
size=900;
printf("All possible combinations of three digit numbers from 0-9 -\n");
combinations(arr,&base,&size,tmp);
for(i=0;i<900;i++) printf("%d ",arr[i]);
return 0;
}