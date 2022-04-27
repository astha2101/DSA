#include<iostream>
using namespace std;
int main()
{
int arr[10];
for(int i=0;i<10;i++)
{
cout<<"Enter a number:";
cin>>arr[i];
}
int y=1;
int num,j;
while(y<10)
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
for(int i=0;i<10;i++)
{
cout<<arr[i]<<endl;
}
return 0;
}