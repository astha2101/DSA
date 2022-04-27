#include<stdio.h>
int main()
{
int queue[10],front,rear,ch,num;
front=0;
rear=0;
while(1)
{
printf("1. Add to queue\n");
printf("2. Remove from queue\n");
printf("3. Exit\n");
printf("Enter your choice : ");
scanf("%d",&ch);
if(ch==1)
{
if(rear==10)
{
printf("Queue is full, cannot add more elements to queue\n");
}
else
{
printf("Enter the number to be added in the queue : ");
scanf("%d",&num);
queue[rear]=num;
rear++;
printf("%d added to the queue\n",num);
}
}
if(ch==2)
{
if(rear==0)
{
printf("Queue is empty\n");
}
else
{
num=queue[front];
front++;
if(front==rear)
{
front=rear=0;
}
printf("%d is removed from the queue\n",num);
}
}
if(ch==3) break;
}
return 0;
}