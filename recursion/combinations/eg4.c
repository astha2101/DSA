#include<stdio.h>
int main()
{
char str[5]="abcde";
int n=5;
for(int i=0;i<n;i++)
{
for(int j=0;j<(n-i);j++)
{
for(int k=j;k<=(j+i);k++)
{
printf("%c",str[k]);
}
printf("\n");
}
}
return 0;
}
