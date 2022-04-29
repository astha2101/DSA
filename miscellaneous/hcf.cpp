#include<iostream>
using namespace std;

int main()
{
int a,b;
cin>>a>>b;
int divisor,dividend;
if(a>b)
{
dividend=a;
divisor=b;
}
else{
dividend=b;
divisor=a;
}
int rem=divisor;
while(rem>0)
{
rem=dividend%divisor;
dividend=divisor;
divisor=rem;
}
cout<<"HCF is :"<<dividend<<endl;
return 0;
}
