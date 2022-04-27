#include<stdio.h>
#include<stdlib.h>
typedef struct linked_list
{
int num;
struct linked_list *next;
}LIST;
void insert(LIST **head,int num)
{
LIST *temp,*curr;
temp=(LIST *)malloc(sizeof(LIST));
temp->num=num;
temp->next=(*head);
*head=temp;
return;
}
int main()
{
int arr[10],i,j,max,min,sizeOfArray,num;
LIST *temp;
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
max=arr[0];
min=arr[0];
for(i=1;i<=9;i++)
{
if(arr[i]>max) max=arr[i];
if(arr[i]<min) min=arr[i];
}
sizeOfArray=(max-min)+1;
LIST *lists[sizeOfArray];
for(i=0;i<=sizeOfArray;i++) lists[i]=NULL;
for(i=0;i<=9;i++)
{
num=arr[i]-min;
insert(&lists[num],arr[i]);
}
j=0;
for(i=0;i<=sizeOfArray;i++)
{
if(lists[i]!=NULL)
{
temp=lists[i];
while(temp!=NULL)
{
arr[j]=temp->num;
temp=temp->next;
j++;
}
}
}
for(i=0;i<=9;i++) printf("%d\n",arr[i]);
return 0;
}