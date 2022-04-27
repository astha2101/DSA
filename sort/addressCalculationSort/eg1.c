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
temp->next=NULL;
if(*head==NULL || (*head)->num >=temp->num)
{
temp->next=(*head);
*head=temp;
return;
}
curr=*head;
while(curr->next!=NULL && curr->next->num < temp->num )
{
curr=curr->next;
}
temp->next=curr->next;
curr->next=temp;
}
int main()
{
int arr[10],i,j,max,digitCount,num;
LIST *lists[10];
LIST *temp;
for(i=0;i<=9;i++)
{
lists[i]=NULL;
}
for(i=0;i<=9;i++)
{
printf("Enter a number : ");
scanf("%d",&arr[i]);
}
max=arr[0];
for(i=1;i<=9;i++)
{
if(arr[i]>max) max=arr[i];
}
digitCount=0;
while(max>0)
{
digitCount++;
max=max/10;
}
for(i=0;i<=9;i++)
{
num=arr[i];
for(j=0;j<digitCount-1;j++) num=num/10;
insert(&lists[num],arr[i]);
}
j=0;
for(i=0;i<=9;i++)
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