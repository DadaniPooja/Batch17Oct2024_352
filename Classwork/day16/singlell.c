#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int val;
   struct node *ptr;
}NODE;

int main()
{
   NODE h1,h2,h3;
   NODE *ptr1=NULL;

   h1.val=10;
   h1.ptr=NULL;

   h2.val=20;
   h2.ptr=NULL;

   h3.val=30;
   h3.ptr=NULL;

   printf("The values are \n%d\n%d\n%d\n",h1.val,h2.val,h3.val);

   //Making relationship

   h1.ptr=&h2;
   h2.ptr=&h3;


  //traverse

  ptr1=&h1;
  while(ptr1!=NULL)
  {
    printf("%d->",ptr1->val);
	ptr1=ptr1->ptr;
  }
  printf("NULL");

  printf("\n");
  return 0;
}
