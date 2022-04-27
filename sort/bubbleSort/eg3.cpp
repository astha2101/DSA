#include<iostream>
using namespace std;
void bubbleSort(int *arr,int n)
{
for(int m=n-1;m>=0;m--)
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
}
int main()
{
int req;
cout<<"Enter requirement :";
cin>>req;
int *arr=new int[req];
for(int i=0;i<req;i++)
{
printf("Enter a number :");
cin>>arr[i];
}
bubbleSort(arr,req);
for(int i=0;i<req;i++) cout<<arr[i]<<endl;
return 0;
}