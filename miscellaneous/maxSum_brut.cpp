#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cout<<"Enter a number:"<<endl;
cin>>arr[i];
}
int maxSum=0;
for(int i=0;i<n-1;i++)
{
int sum=arr[i];
if(sum>maxSum) maxSum=sum;
for(int j=i+1;j<n;j++)
{
sum+=arr[j];
if(sum>maxSum) maxSum=sum;
}
}
cout<<"Max sum : "<<maxSum<<endl;
return 0;
}
