#include<iostream>
using namespace std;

int _gcd(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    int dividend,divisor;
    if(a>b)
    {
        dividend=a;
        divisor=b;
    }
    else
    {
        divisor=a;
        dividend=b;
    }
    return _gcd(divisor,dividend%divisor);
}

int gcd(int *arr,int n)
{
int res=arr[0];
for(int i=1;i<n;i++)
{
res=_gcd(res,arr[i]);
}
return res;
}

int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
{
cout<<"Enter a number : "<<endl;
cin>>arr[i];
}
cout<<"GCD of given numbers is : "<<gcd(arr,n)<<endl;
return 0;
}
