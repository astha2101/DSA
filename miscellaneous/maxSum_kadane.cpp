#include<iostream>
using namespace std;

int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cout<<"Enter a number: "<<endl;
cin>>arr[i];
}
int localMax=arr[0];
int globalMax=arr[0];
for(int i=1;i<n;i++)
{
localMax = arr[i]>localMax+arr[i]?arr[i]:localMax+arr[i];
globalMax=localMax>globalMax?localMax:globalMax;
}
cout<<"Max sum of the subarray is : "<<globalMax<<endl;
return 0;
}
