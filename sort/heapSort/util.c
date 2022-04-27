#define true 1
#define TRUE 1
#define True 1
#define false 0
#define FALSE 0
#define False 0
int convertToInt(char *str,int *success)
{
int result=0,y;
y=1;
if(*str=='-')
{
str++;
y=-1;
}
while(*str)
{
if(*str<48||*str>57)
{
*success=false;
return 0;
}
result=(result*10)+(*str-48);
str++;
}
*success=true;
return result*y;
}