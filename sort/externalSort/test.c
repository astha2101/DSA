#include<stdio.h>
#include<stdlib.h>
int main()
{
FILE *f,num;
f=fopen("dataFile1.d","rb");
while(!feof(f))
{
fread(&num,sizeof(int),1,f);
printf("%d  ",num);
}
return 0;
}