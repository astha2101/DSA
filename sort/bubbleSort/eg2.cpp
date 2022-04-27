#include<iostream>
using namespace std;
int main()
{
int req;
cout<<"Enter requirement :";
cin>>req;
int *arr=new int[req];
for(int i=0;i<req;i++)
{
cout<<"Enter a number :";
cin>>arr[i];
}
for(int m=req-1;m>=0;m--)
{
for(int e=0,f=1;e<m;e++,f++)
{
if(arr[f]<arr[e])
{
int g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
}
for(int i=0;i<req;i++) cout<<arr[i]<<endl;
return 0;
}