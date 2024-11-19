#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int val;
   struct node *ptr;
}NODE;

void printList(NODE *);
void appendNode(NODE *,NODE *);

int main()
{
   NODE h1,h2,h3,h4,h5,h6;
   NODE *ptr1=NULL;

   h1.val=10;
   h1.ptr=NULL;

   h2.val=20;
   h2.ptr=NULL;

   h3.val=30;
   h3.ptr=NULL;

   printf("The values are \n%d\n%d\n%d\n",h1.val,h2.val,h3.val);
   printList(ptr1);
   //Making relationship

   h1.ptr=&h2;
   h2.ptr=&h3;

   // create new node h4 at the end

  h4.val=40;
  h4.ptr=NULL;

  //h3.ptr=&h4;

  ptr1=&h1;
  appendNode(ptr1,&h4);
 
  ptr1 =&h1;
  printList(ptr1);

  // create a node btw h1 and ha
  h5.val=50;
  h5.ptr=NULL;

  h1.ptr=&h5;
  h5.ptr=&h2;

  // create a new at the begining

  h6.val=60;
  h6.ptr=NULL;

  h6.ptr=&h1;

//traverse

  ptr1 = &h1;
  printList(ptr1);

  printf("\n");
  return 0;
}

void printList(NODE *head)
{
  printf("\nList using loop and function\n");
  while(head!=NULL)
  {
    printf("%d->",head->val);
	head=head->ptr;
  }
  printf("NULL");
  printf("\n");
}

void appendNode(NODE *head, NODE *nn)
{
   printf("\nIn appendNode\n");
      while(head->ptr!=NULL)
     {
        printf("%d->",head->val);
        head=head->ptr;
     }
     printf("%d",head->val);
	 head->ptr=nn; //adding new to the end of the list
}
