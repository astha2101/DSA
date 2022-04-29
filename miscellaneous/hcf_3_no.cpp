#include<iostream>
using namespace std;

int gcd(int a,int b)
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
    return gcd(divisor,dividend%divisor);
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int res=gcd(a,b);
    cout<<"Hcf is : "<<gcd(res,c)<<endl;
    return 0;
}
