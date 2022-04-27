// technique 3 :- create a max heap of size of the element number
#include<stdio.h>
int main()
{
int x[10],i,ci,ri,g,k;
int ub,lb,lci,rci,swi;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&x[i]);
}
printf("Enter the number of the nth smallest element : ");
scanf("%d",&k);
if(k<=0 || k>10)
{
printf("Invalid element number ");
return 0;
}
i=0;
while(i<k)
{
ci=i;
while(ci>0)
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
i++;
}
if(k==10)
{
printf("%dth smallest element is %d",k,x[0]);
return 0;
}
lb=0;
ub=k-1;
while(i<=9)
{
if(x[i]<x[lb])
{
x[lb]=x[i];
ri=lb;
while(ri<ub)
{
lci=(ri*2)+1;
if(lci>ub) break;
rci=lci+1;
if(rci>ub)
{
swi=lci;
}
else
{
if(x[lci]>x[rci]) swi=lci;
else swi=rci;
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
i++;
}
if(k==1)
{
printf("%dst smallest element is : %d",k,x[0]);
}
else if(k==2)
{
printf("%dnd smallest element is : %d",k,x[0]);
}
else if(k==3)
{
printf("%drd smallest element is : %d",k,x[0]);
}
else printf("%dth smallest element is : %d",k,x[0]);
return 0;
}