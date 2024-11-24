#include <stdio.h>

#define MAX 5

int rear=0;
int front=0;

int q[MAX];

void enqueue(int);
void dequeue();
void dispQueue();

int main()
{
   enqueue(10);
   enqueue(20);//if the max is reached the values will not pushed and it gives the line queue is full
   enqueue(30);

   dispQueue();
    
   dequeue(10);// delete the value 10 in the queue
   dispQueue();

   printf("\n");
   return 0;
}

void dispQueue()
{
   int i;
   if(front==rear)
   {
      printf("\nEmpty Queue\n");
	  return;
   }
   printf("\nQueue is\n");
   for(i=front;i<rear;i++)
       printf("%d ",q[i]);
   printf("\n");
}

void enqueue(int val)
{
   if(rear==MAX)
   {
       printf("\nQueue is full\n");
	   return;
   }
   q[rear]=val;
   rear++;
}

void dequeue()
{
   if(front==rear)
   {
      front=0;//reset the queue
	  rear=0;
	  printf("\nEmpty Queue\n");
	  return;
   }
   printf("\n%d is dequeued from the queue",q[front]);
   front++;
}
