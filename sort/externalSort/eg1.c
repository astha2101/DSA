#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *f;
int num;
f=fopen("data.d","wb");
srand(time(0));
for(int i=0;i<130000000;i++)
{
num=rand();
//printf("%d ",num);
fwrite(&num,sizeof(int),1,f);
}
printf("\n");
fclose(f);
f=fopen("data.d","rb");
fseek(f,0L,SEEK_END);
long int size=ftell(f);
fclose(f);
printf("Size is : %ld\n",size);
long int totalNumberOfNumbers=(size)/4;
printf("Number of records : %ld\n",totalNumberOfNumbers);
return 0;
}