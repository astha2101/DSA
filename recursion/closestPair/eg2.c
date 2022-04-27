#include<stdio.h>
#include<math.h>
int findPartitionPoint(int x[][2],int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e][0]<=x[lb][0]) e++;
while(x[f][0]>x[lb][0]) f--;
if(e<f)
{
g=x[e][0];
x[e][0]=x[f][0];
x[f][0]=g;
}
else
{
g=x[lb][0];
x[lb][0]=x[f][0];
x[f][0]=g;
}
}
return f;
}
void sort(int arr[][2],int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(arr,lb,ub);
sort(arr,lb,pp-1);
sort(arr,pp+1,ub);
}
void findClosestPair(int arr[][2],int lb,int ub,int pair[][2])
{
int a,b,e,f,minDistance,dist;
a=arr[lb+1][0]-arr[lb][0];
b=arr[lb+1][1]-arr[lb][1];
minDistance=sqrt((a*a)+(b*b));
for(e=lb;e<ub-1;e++)
{
for(f=e+1;f<ub;f++)
{
a=arr[f][0]-arr[e][0];
b=arr[f][1]-arr[e][1];
dist=sqrt(a*a+b*b);
if(dist<minDistance)
{
minDistance=dist;
pair[0][0]=e;
pair[0][1]=f;
}
}
}
}
int main()
{
int arr[20][2]={{-3,5},{3,7},{2,3},{-1,1},{-1,6},{-6,-3},{3,1},{1,5},{5,2},{0,4},{-6,5},{4,2},{1,0},{2,3},{-4,-6},{5,5},{6,1},{1,-1},{4,2},{0,7}};
int minDistance;
int e,f,dist,a,b;
int pair[1][2];
sort(arr,0,19);
printf("Pairs are : \n");
for(e=0;e<20;e++)
{
printf("(%d %d)\n",arr[e][0],arr[e][1]);
}
int mid=10;
findClosestPair(arr,0,10,pair);
printf("Left side closest pair : (%d %d ) and (%d %d )\n",arr[pair[0][0]][0],arr[pair[0][0]][1],arr[pair[0][1]][0],arr[pair[0][1]][1]);
findClosestPair(arr,10,20,pair);
printf("Right side closest pair : (%d %d ) and (%d %d )\n",arr[pair[0][0]][0],arr[pair[0][0]][1],arr[pair[0][1]][0],arr[pair[0][1]][1]);
return 0;
}