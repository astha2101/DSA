// Brute-force algorithm
#include<stdio.h>
#include<math.h>
int main()
{
int arr[6][2]={{-3,5},{3,7},{2,3},{-1,1},{-1,6},{-6,-3}};
int minDistance;
int e,f,dist,a,b;
int pair[1][2];
a=arr[1][0]-arr[0][0];
b=arr[1][1]-arr[0][1];
minDistance=sqrt((a*a)+(b*b));
for(e=0;e<5;e++)
{
for(f=e+1;f<6;f++)
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
printf("Pairs are :\n");
for(e=0;e<6;e++)
{
printf("(%d %d)\n",arr[e][0],arr[e][1]);
}
printf("Closest pair are (%d,%d) and (%d,%d)",arr[pair[0][0]][0],arr[pair[0][0]][1],arr[pair[0][1]][0],arr[pair[0][1]][1]);
return 0;
}