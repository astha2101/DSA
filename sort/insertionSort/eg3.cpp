#include<iostream>
using namespace std;
template<typename T>
void insertionSort(T *arr,int n,int(*ptr)(T,T))
{
int y,j;
T num;
y=1;
while(y<n)
{
num=arr[y];
j=y-1;
while(j>=0 && ptr(arr[j],num)<0)
{
arr[j+1]=arr[j];
j--;
}
arr[j+1]=num;
y++;
}
}
int comparator(int a,int b)
{
return a-b;
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
insertionSort<int>(arr,req,comparator);
for(int i=0;i<req;i++) cout<<arr[i]<<endl;
return 0;
}