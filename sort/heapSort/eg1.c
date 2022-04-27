#include<stdio.h>
#include<malloc.h>
#include "util.h"
void heap(int *,int,int);
int main(int count,char *str[])
{
int *array,e,i,size,num,converted;
if(count==1)
{
printf("Usage [heapsort num1 num2 num3---------] ");
return 0;
}
array=(int *)malloc(sizeof(int)*(count-1));
size=count-1;
i=0;
for(e=1;e<=size;e++)
{
num=convertToInt(str[e],&converted);
if(converted)
{
array[i]=num;
i++;
}
}
if(i==0)
{
free(array);
printf("Usage [heap num1 num2 num3 -----------------]");
return 0;
}
size=i;
heap(array,0,size-1);
for(e=0;e<=size-1;e++)
{
printf("%d\n",array[e]);
}
free(array);
return 0;
}
void heap(int *x,int lowerBound,int upperBound)
{
int y,ci,ri,lci,rci,swi,g;
y=lowerBound+1;
while(y<=upperBound)
{
ci=y;
while(ci>lowerBound)
{
ri=(ci-1)/2;
if(x[ci]>x[ri])
{
g=x[ci];
x[ci]=x[ri];
x[ri]=g;
ci=ri;
}
else
{
break;
}
}
y++;
}
//implement heapSort
while(upperBound>lowerBound)
{
g=x[lowerBound];
x[lowerBound]=x[upperBound];
x[upperBound]=g;
upperBound--;
ri=lowerBound;
while(ri<upperBound)
{
lci=(ri*2)+1;
if(lci>upperBound) break;
rci=lci+1;
if(rci>upperBound)
{
swi=lci;
}
else
{
if(x[lci]>x[rci]) swi=lci; else swi=rci;
}
if(x[swi]>x[ri])
{
g=x[ri];
x[ri]=x[swi];
x[swi]=g;
ri=swi;
}
else
{
break;
}
}
}
}