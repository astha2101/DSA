#include<iostream>
using namespace std;


int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cout<<"Enter a number :"<<endl;
cin>>arr[i];
}
int sum,loc_sum=0;
int si=0,ei=0;
cout<<"Enter the sum :"<<endl;
cin>>sum;
bool found=false;
for(int i=0;i<n-1;i++)
{
loc_sum=arr[i];
if(loc_sum==sum)
{
cout<<"Subarray with sum equal to "<<sum<<"is :";
cout<<arr[i]<<endl;
cout<<"Index : "<<i<<endl;
found=true;
break;
}
for(int j=i+1;j<n;j++)
{
loc_sum+=arr[j];
if(loc_sum == sum)
{
cout<<"Subarrays with sum equal to "<<sum<<endl;
for(int e=i;e<=j;e++) 
{
cout<<arr[e]<<" ";
cout<<"Index : "<<e<<endl;
}
found=true;
break;
}
}
}
if(found ==false) cout<<"No such subarray found with the given sum."<<endl;
return 0;
}
