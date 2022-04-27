#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void linearSort(void *ptr,int n,int size,int (*p2f)(void *,void *))
{
int e,f,g,w;
void *a,*b,*c;
c=(void *)malloc(size);
for(e=0;e<n-1;e++)
{
for(f=e+1;f<n;f++)
{
a=ptr+(f*size);
b=ptr+(e*size);
w=p2f(a,b);
if(w<0)
{
memcpy(c,(const void *)a,size);
memcpy(a,(const void *)b,size);
memcpy(b,(const void *)c,size);
}
}
}
}
int comparator(void *a,void *b)
{
int *x=(int *)a;
int *y=(int *)b;
return *x-*y;
}
int main()
{
int req,*arr,i;
printf("Enter requirement :");
scanf("%d",&req);
arr=(int *)malloc(sizeof(int)*req);
for(i=0;i<req;i++)
{
printf("Enter a number :");
scanf("%d",&arr[i]);
}
linearSort(arr,req,sizeof(int),comparator);
for(i=0;i<req;i++) printf("%d\n",arr[i]);
return 0;
}