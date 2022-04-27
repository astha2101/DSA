#include<stdio.h>
#include<stdlib.h>
int copies=0;
void findPower(int e,int p,int *arr)
{
copies++;
if(p==0) arr[p]=1;
if(arr[p/2]==0) findPower(e,p/2,arr);
if(p%2==0) arr[p]=arr[p/2]*arr[p/2];
else arr[p]=arr[p/2]*arr[p/2]*e;
}
int main()
{
int e,p,i;
int *arr;
printf("Enter a number : ");
scanf("%d",&e);
printf("Enter power : ");
scanf("%d",&p);
arr=(int *)malloc(sizeof(int)*(p+1));
for(i=0;i<=p;i++) arr[i]=0;
findPower(e,p,arr);
printf("%d to the power %d is %d\n",e,p,arr[p]);
printf("Number of copies : %d",copies);
free(arr);
return 0;
}