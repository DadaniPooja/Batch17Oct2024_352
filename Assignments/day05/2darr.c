#include <stdio.h>
#include <strings.h>
#define ROWS 2
#define COLS 3

int init(int arr[ROWS][COLS]);
int search_update(int arr[ROWS][COLS]);
void display(int arr[ROWS][COLS]);

int main()
{
   int arr[ROWS][COLS]={{0}};
   int ch;
   while(1)
   {
     printf("\nPress..\n");
	 printf("1. Initialise array\n");
	 printf("2. Serach and update\n");
	 printf("3. Display the array\n");
	 printf("4. Exit\n");

	 printf("Enter choice: ");
	 scanf("%d",&ch);

	 switch(ch)
	 {
	   case 1:
	          init(arr);
			  break;
	   case 2:
	          search_update(arr);
			  break;
	   case 3:
	          display(arr);
			  break;
	   case 4:
	          printf("\nExiting...\n");
			  return 0;
	   default:
	         printf("Enter the valid choice\n");
     }
   }
 return 0;
}

int init(int arr[ROWS][COLS])
{
   int i,j;
   if(arr[ROWS][COLS]==0)
       printf("Array initialized\n");   
   printf("Enter elements\n");
   for(i=0;i<ROWS;i++)
   {
     for(j=0;j<COLS;j++)
	 {
	   scanf("%d",&arr[i][j]);
	 }
   }
   return 0;
}

int search_update(int arr[ROWS][COLS])
{
   int s,n,i,j;
   printf("\nEnter element to searched and update: ");
   scanf("%d",&s);
   printf("\nEnter the new value to be update: ");
   scanf("%d",&n);
   for(i=0;i<ROWS;i++)
   {
     for(j=0;j<COLS;j++)
	 {
	   if(arr[i][j]==s)
	   {
	      arr[i][j]=n;
		  return 0;
	   }
	 }
   }
   printf("\nElement not found\n");
   return 0;
}

void display(int arr[ROWS][COLS])
{
  int i,j;
  for(i=0;i<ROWS;i++)
  {
    for(j=0;j<COLS;j++)
	{
	  printf("%d ",arr[i][j]);
	}
	printf("\n");
  }
}
