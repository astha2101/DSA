#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *f;
int i,num;
f=fopen("data.d","wb");
srand(time(0));
for(i=0;i<5000;i++)
{
num=rand()%100;
fwrite(&num,sizeof(int),1,f);
}
fclose(f);
return 0;
}