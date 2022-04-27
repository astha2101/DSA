#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
int x[10],y,largest,*tmp,num,z,i;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
largest=x[0];
for(y=1;y<=9;y++)
{
if(x[y]>largest) largest=x[y];
}
tmp=(int *)malloc(sizeof(int)*(largest+1));
memset(tmp,0,sizeof(int)*(largest+1));
for(y=0;y<=9;y++)
{
num=x[y];
tmp[num]=tmp[num]+1;
}
z=0;
for(y=0;y<=largest;y++)
{
if(tmp[y]!=0)
{
for(i=0;i<tmp[y];i++)
{
x[z]=y;
z++;
}
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}