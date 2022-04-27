// technique 2:- by creating a min heap of all elements 
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
while(i<=9)
{
ci=i;
while(ci>0)
{
ri=(ci-1)/2;
if(x[ci]<x[ri])
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
//adjusting heap
ub=9;
lb=0;
for(i=0;i<k;i++)
{
g=x[lb];
x[lb]=x[ub];
x[ub]=g;
ub--;
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
if(x[lci]<x[rci]) swi=lci;
else swi=rci;
}
if(x[swi]<x[ri])
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
if(k==1)
{
printf("%dst smallest element is : %d",k,x[10-k]);
}
else if(k==2)
{
printf("%dnd smallest element is : %d",k,x[10-k]);
}
else if(k==3)
{
printf("%drd smallest element is : %d",k,x[10-k]);
}
else printf("%dth smallest element is : %d",k,x[10-k]);
return 0;
}



                                         