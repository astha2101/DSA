#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
FILE *f;
int num,i=0;
f=fopen("data.d","rb");
fseek(f,0,2);
long int size=ftell(f);
fclose(f);
printf("Size is : %ld\n",size);
long int totalNumberOfNumbers=(size)/4;
printf("Number of records : %ld\n",totalNumberOfNumbers);
f=fopen("data.d","rb");
while(ftell(f)!=size)
{
if(feof(f)) break;	
fread(&num,sizeof(int),1,f);
printf("%d ",num);
}
printf("\n");
fclose(f);
return 0;
}