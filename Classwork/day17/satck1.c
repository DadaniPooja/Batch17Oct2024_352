/*demo on stack using arrays */
 //in .c file

#include<stdio.h>
#include<stdlib.h>

#define MAX 5

int bottom=-1;
int top=-1; // don't place in header files, place it in the .h file itself to avoid multiple variables,

int push(int);
int pop();        //.h file
void dispStack();

int stackCont[MAX];

int push(int v)
{
   if(top == MAX-1)
   {
      printf("\nStack/container is FULL\n");
	  return 0;
   }
   top++;
   stackCont[top]=v; // first increment cuz top=-1 to print the elements

   return 0;
}

int pop()
{
  int val;
  if(top == bottom)
  {
     printf("\nStack/container is EMPTY\n");
	 return 0;
  }
  val= stackCont[top];  // storing the value in some memory
  top--; // lowering the values of top
  return v; // to the call function sending the value which is temporary removes
}

void dispStack()
{
  int i;
  if(top == bottom)
  {
     printf("\nStack/container is EMPTY\n");
     return 0;
  }

  for(i=top;i>bottom;i++) // if i inserted only two elementd the the max is not taken
  {
     printf("\n%d",stackCont[i]);
	 return;
  }
}


// main.c file 

#include <stdio.h>
#include <stack_v01.h>

//driver code for stack operations
int main()
{
  int v,i;
 //  v=pop();
 //  printf("\n%d element is deleted from the container/stack",v);

  push(10);
  push(11);
  push(12);
  push(13);
  dispStack();
 
  for(i=0;i<MAX;i++)
  {
     v=pop();
	 printf("\n%d element is deleted from the container/stack",v);
	 dispStack();
  }

  printf("\n");
  return 0;
