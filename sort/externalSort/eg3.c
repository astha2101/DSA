#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void quickSort(int *x,int lowerBound,int upperBound)
{
int n,sizeOfStack,g,e,f,top,lb,ub;
int *lbStack,*ubStack;
n=ub-lb+1;
sizeOfStack=n/2+1;
lbStack=(int *)malloc(sizeof(int)*sizeOfStack);
ubStack=(int *)malloc(sizeof(int)*sizeOfStack);
top=sizeOfStack;
top--;
lbStack[top]=lowerBound;
ubStack[top]=upperBound;
while(top!=sizeOfStack)
{
lb=lbStack[top];
ub=ubStack[top];
top++;
e=lb;
f=ub;
while(e<f)
{
while(e<ub&&x[e]<=x[lb]) e++;
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
if(f+1<ub)
{
top--;
lbStack[top]=f+1;
ubStack[top]=ub;
}
if(lb<f-1)
{
top--;
lbStack[top]=lb;
ubStack[top]=f-1;
}
}
free(lbStack);
free(ubStack);
}
struct file_data
{
int num;
int isAlive;
};
int getMinIndex(struct file_data  **arr)
{
int min,i,j,index;
for(i=0;i<=9;i++)
{
if(arr[i]->isAlive)
{
min=arr[i]->num;
break;
}
}
if(i==10)
{
index=i;
return index;
}
index=i;
for(j=i+1;j<=9;j++)
{
if(arr[j]->num<min && arr[j]->isAlive)
{
min=arr[j]->num;
index=j;
}
}
return index;
}
void merge(int numberOfRecords)
{
int i,j,_fileNumber,num,index,numberOfFiles,size;
int dataRead=0,dataWritten=0;
char fileNumber[10],fileName[30];
int canRead[10];
struct file_data **fileData;
FILE *files[10];
FILE *outputFile;
size=numberOfRecords*4;
numberOfFiles=10;
fileData=(struct file_data **)malloc(sizeof(struct file_data *)*10);
for(i=0;i<=9;i++)
{
canRead[i]=1;
files[i]=(FILE *)malloc(sizeof(FILE));
fileData[i]=NULL;
}
_fileNumber=1;
for(i=0;i<=9;i++)
{
sprintf(fileName,"dataFile");
itoa(_fileNumber,fileNumber,10);
strcat(fileName,fileNumber);
strcat(fileName,".d");
files[i]=fopen(fileName,"rb");
_fileNumber++;
}
outputFile=fopen("data.d","wb");
while(numberOfFiles>0)
{
for(i=0;i<=9;i++)
{
if(canRead[i])
{
if(ftell(files[i])==size)
{
numberOfFiles--;
fileData[i]->isAlive=0;
if(numberOfFiles==0) break;
}
else
{
fread(&num,sizeof(int),1,files[i]);
dataRead++;
if(fileData[i]==NULL)
{
fileData[i]=(struct file_data *)malloc(sizeof(struct file_data));
fileData[i]->isAlive=1;
}
fileData[i]->num=num;
}
}
}
index=getMinIndex(fileData);
if(index<=9) fwrite(&fileData[index]->num,sizeof(int),1,outputFile);
dataWritten++;
for(j=0;j<=9;j++)
{
if(j==index) canRead[j]=1;
else canRead[j]=0;
}
}
fclose(outputFile);
for(i=0;i<=9;i++)
{
fclose(files[i]);
free(files[i]);
}
for(i=0;i<=9;i++) free(fileData[i]);
free(fileData);
}
int main()
{
FILE *file,*f,*temp;
int num;
int min;
char fileNumber[10];
char fileName[30];
file=fopen("data.d","rb");
fseek(file,0L,SEEK_END);
long int size=ftell(file);
fclose(file);
long int totalNumberOfNumbers=(size)/4;
int sizeOfEachFile=totalNumberOfNumbers/10;
int numberOfRecordsInEachFile=totalNumberOfNumbers/10;
//creating subunits of the file
file=fopen("data.d","rb");
int _fileNumber=1;
for(int i=0;i<=9;i++)
{
sprintf(fileName,"dataFile");
itoa(_fileNumber,fileNumber,10);
strcat(fileName,fileNumber);
strcat(fileName,".d");
f=fopen(fileName,"wb");
for(int i=0;i<numberOfRecordsInEachFile;i++)
{
fread(&num,sizeof(num),1,file);
fwrite(&num,sizeof(num),1,f);
}
fseek(f,0L,SEEK_END);
int s=ftell(f);
fclose(f);
_fileNumber++;
}
fclose(file);
//sorting the subunits
_fileNumber=1;
for(int i=0;i<=9;i++)
{
sprintf(fileName,"dataFile");
itoa(_fileNumber,fileNumber,10);
strcat(fileName,fileNumber);
strcat(fileName,".d");
f=fopen(fileName,"rb");
if(f==NULL) printf("Error\n");
int *arr=(int *)malloc(sizeof(int)*numberOfRecordsInEachFile);
for(int i=0;i<numberOfRecordsInEachFile;i++)
{
fread(&num,sizeof(num),1,f);
arr[i]=num;
}
fclose(f);
int ub=numberOfRecordsInEachFile-1;
quickSort(arr,0,ub);
f=fopen(fileName,"wb");
for(int i=0;i<numberOfRecordsInEachFile;i++)
{
num=arr[i];
fwrite(&num,sizeof(num),1,f);
}
fclose(f);
_fileNumber++;
free(arr);
}
// merge the subunits
merge(numberOfRecordsInEachFile);
return 0;
}