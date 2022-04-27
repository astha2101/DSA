#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/*int findPartitionPoint(int *x,int lb,int ub)
{
int e,f,g;
e=lb;
f=ub;
while(e<f)
{
while(e<ub && x[e]<=x[lb]) e++;
while(x[f]>x[lb]) f--;
if(e<f)
{
g=x[e];
x[e]=x[f];
x[f]=g;
}
else
{
g=x[lb];
x[lb]=x[f];
x[f]=g;
}
}
return f;
}
void quickSort(int *x,int lb,int ub)
{
int pp;
if(ub<=lb) return;
pp=findPartitionPoint(x,lb,ub);
quickSort(x,lb,pp-1);
quickSort(x,pp+1,ub);
}
*/
void generateFileToSort()
{
printf("Generate file to sort got called\n");
FILE *f;
int num;
f=fopen("data.d","w");
srand(time(0));
for(int i=0;i<130000000;i++)
{
num=rand();
fwrite(&num,sizeof(num),1,f);
}
fclose(f);
}
int main()
{
printf("Hi\n");
generateFileToSort();
FILE *file,*f;
char fileNumber[10];
int num;
// generating files of x/10
int _fileNumber=1;
for(int t=0;t<=9;t++)
{
char fileName[]="dataFile";
itoa(_fileNumber,fileNumber,10);
strcat(fileName,fileNumber);
strcat(fileName,".d");
f=fopen("data.d","r");
file=fopen(fileName,"w");
for(int i=0;i<13000000;i++)
{
printf("Transfering data to file no %d\n",_fileNumber);
fread(&num,sizeof(num),1,f);
fwrite(&num,sizeof(num),1,file);
}
fclose(file);
_fileNumber++;
}
fclose(f);
/*
// sorting files individually
_fileNumber=1;
for(int i=0;i<1;i++)
{
char fileName[]="datafile";
itoa(_fileNumber,fileNumber,10);
strcat(fileName,fileNumber);
strcat(fileName,".d");
f=fopen(fileName,"r");
int arr[13000000];
printf("Before sorting : \n");
for(int i=0;i<13000000;i++)
{
fread(&num,sizeof(num),1,f);
printf("%d ",num);
arr[i]=num;
}
fclose(f);
int lb=0;
int ub=12900000;
quickSort(arr,lb,ub);
f=fopen(fileName,"w");
for(int i=0;i<13000000;i++)
{
num=arr[i];
fwrite(&num,sizeof(num),1,f);
}
fclose(f);
f=fopen(fileName,"r");
printf("After sorting :\n");
for(int i=0;i<13000000;i++)
{
fread(&num,sizeof(num),1,f);
printf("%d ",num);
}
fclose(f);
}
*/
return 0;
}