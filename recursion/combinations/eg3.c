#include<stdio.h>
#include<string.h>
void _printAllCombinations(char *str,int start,int end)
{
int i,k;
char g;
if(start==end)
{
for(i=0;i<=end;i++) printf("%c",str[i]);
printf("\n");
return;        
}
for(int i=start;i<=end;i++)
{
for(k=start;k<i;k++) if(str[i]==str[k]) break;
if(k<i) continue;
g=str[start];
str[start]=str[i];
str[i]=g;
_printAllCombinations(str,start+1,end);
g=str[start];
str[start]=str[i];
str[i]=g;
}
}
void printAllCombinations(char *str)
{
_printAllCombinations(str,0,strlen(str)-1);
}
int main()
{
char str[11];
int start,end;
printf("Enter a string : ");
scanf("%s",str);
printAllCombinations(str);
return 0;
}