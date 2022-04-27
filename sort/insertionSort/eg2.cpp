#include<iostream>
using namespace std;
void insertionSort(int *arr,int n)
{
int j,y,num;
y=1;
while(y<n)
{
num=arr[y];
j=y-1;
while(j>=0 && arr[j]>num)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=num;
y++;
}
}
int main()
{
int req;
cout<<"Enter your requirement :";
cin>>req;
int *arr=new int[req];
for(int i=0;i<req;i++)
{
cout<<"Enter a number :";
cin>>arr[i];
}
insertionSort(arr,req);
for(int i=0;i<req;i++) cout<<arr[i]<<endl;
return 0;
}