#include<iostream>
using namespace std;
#include<algorithm>
template<typename T>
void bubbleSort(T *arr,int n,int size,int(*p2f)(T ,T))
{
for(int m=n-1;m>=0;m--)
{
for(int e=0,f=1;e<m;e++,f++)
{
int w=p2f(arr[f],arr[e]);
if(w<0)
{
T g=arr[e];
arr[e]=arr[f];
arr[f]=g;
}
}
}
}
int comparator(char a,char b)
{
return (int)(a-b);
}
int main()
{
int req;
cout<<"Enter requirement :";
cin>>req;
char *arr=new char[req];
for(int i=0;i<req;i++)
{
cout<<"Enter  a character :";
cin>>arr[i];
}
bubbleSort<char >(arr,req,sizeof(char),comparator);
for(int i=0;i<req;i++) cout<<arr[i]<<endl;
return 0;
}