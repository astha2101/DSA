#include<stdlib.h>
#include<stdio.h>
typedef struct _queue_node
{
int num;
struct _queue_node *next;
}QueueNode;
typedef struct _queue
{
QueueNode *start;
QueueNode *end;
int size;
}Queue;
void initQueue(Queue *queue)
{
queue->start=NULL;
queue->end=NULL;
queue->size=0;
}
int isQueueEmpty(Queue *queue)
{
return queue->size==0;
}
void addToQueue(Queue *queue,int num)
{
QueueNode *t;
t=(QueueNode *)malloc(sizeof(QueueNode));
t->num=num;
t->next=NULL;
if(queue->start==NULL)
{
queue->start=t;
queue->end=t;
}
else
{
queue->end->next=t;
queue->end=t;
}
queue->size++;
}
int removeFromQueue(Queue *queue)
{
int num;
QueueNode *t;
num=queue->start->num;
t=queue->start;
queue->start=queue->start->next;
if(queue->start==NULL) queue->end=NULL;
free(t);
queue->size--;
return num;
}
void clearQueue(Queue *queue)
{
QueueNode *t;
while(queue->start!=NULL)
{
t=queue->start;
queue->start=queue->start->next;
queue->size--;
free(t);
}
queue->end=NULL;
queue->size=0;
}
void radixSort(int *arr,int lb,int ub)
{
Queue queues[10];
int largest,dc,num,k,e,f,i,y;
for(i=0;i<=9;i++)
{
initQueue(&queues[i]);
}
largest=arr[lb];
for(y=lb+1;y<=ub;y++)
{
if(arr[y]>largest) largest=arr[y];
}
dc=0;
num=largest;
while(num>0)
{
dc++;
num=num/10;
}
e=10;
f=1;
k=1;
while(k<=dc)
{
y=lb;
while(y<=ub)
{
num=arr[y];
i=(num%e)/f;
// add the num to ith queue
addToQueue(&queues[i],num);
y++;
}
// collect all numbers from 10 queues and keep in array
i=lb;
y=0;
while(y<=9)
{
while(!isQueueEmpty(&queues[y]))
{
num=removeFromQueue(&queues[y]);
arr[i]=num++;
i++;
}
y++;
}
e=e*10;
f=f*10;
k++;
}
}
int main()
{
int x[10],y,neglb,negub,poslb,posub,e,f,g,z;
int negativeFound=0,positiveFound=0;
for(y=0;y<=9;y++)
{
printf("Enter a number : ");
scanf("%d",&x[y]);
}
neglb=-1;
negub=-1;
for(y=0;y<=9;y++)
{
if(x[y]<0)
{
if(negativeFound==0)
{
negativeFound=1;
neglb++;
}
negub++;
g=x[y];
x[y]=x[negub];
x[negub]=g;
}
}
poslb=negub+1;
posub=9;
if(poslb!=10) positiveFound=1;
for(y=neglb;y<=negub;y++) x[y]=x[y]*-1;
if(negativeFound==1) radixSort(x,neglb,negub);
if(positiveFound==1)radixSort(x,poslb,posub);
if(negativeFound==1)
{
for(y=neglb,z=negub;y<=z;y++,z--)
{
g=x[y];
x[y]=x[z];
x[z]=g;
x[y]=x[y]*-1;
x[z]=x[z]*-1;
}
}
for(y=0;y<=9;y++) printf("%d\n",x[y]);
return 0;
}