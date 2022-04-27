#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void countingSort(int *arr,int lb,int ub)
{
int largest,y,*tmp,num,z,i;
largest=arr[lb];
for(y=lb+1;y<=ub;y++)
{
if(arr[y]>largest) largest=arr[y];
}
tmp=(int *)malloc(sizeof(int)*(largest+1));
memset(tmp,0,sizeof(int)*(largest+1));
for(y=lb;y<=ub;y++)
{
num=arr[y];
tmp[num]=tmp[num]+1;
}
z=lb;
for(y=0;y<=largest;y++)
{
if(tmp[y]!=0)
{
for(i=0;i<tmp[y];i++)
{
arr[z]=y;
z++;
}
}
}
free(tmp);
}
int main()
{
int x[10],y,neglb,negub,poslb,posub,e,f,g,z;
int negativeFound=0,positiveFound=0;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
neglb=-1;
negub=-1;
for(y=0;y<=9;y++)
{
if(x[y]<0)
{
if(negativeFound==0)
{
negativeFound=1;
neglb++;
}
negub++;
g=x[y];
x[y]=x[negub];
x[negub]=g;
}
}
poslb=negub+1;
posub=9;
if(poslb!=10) positiveFound=1;
if(negativeFound==1) for(y=neglb;y<=negub;y++) x[y]=x[y]*-1;
if(negativeFound==1) countingSort(x,neglb,negub);
if(positiveFound==1) countingSort(x,poslb,posub);
if(negativeFound==1)
{
for(y=neglb,z=negub;y<=z;y++,z--)
{
g=x[y];
x[y]=x[z];
x[z]=g;
x[y]=x[y]*-1;
x[z]=x[z]*-1;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}