#include<iostream>
using namespace std;
int main()
{
int arr[10];
for(int i=0;i<10;i++)
{
cout<<"Enter a number :";
cin>>arr[i];
}
for(int m=9;m>=0;m--)
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
for(int i=0;i<10;i++) cout<<arr[i]<<endl;
return 0;
}