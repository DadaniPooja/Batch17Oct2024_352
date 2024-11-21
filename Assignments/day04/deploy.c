#include <stdio.h>

int main()
{
   int test1,test2,test3,project,eligible=1;

   printf("Enter test1, test2, test3 and project scores\n");
   scanf("%d%d%d%d",&test1,&test2,&test3,&project);

   if(test1<75)
      eligible=0;
   else if(test2<75)
      eligible=0;
   else if(test3<70)
      eligible=0;
   else if(project<75)
      eligible=0;
	
   switch(eligible)
   {
       case 1:
	          printf("\nEligible\n");
			  break;
	   case 0:
              printf("\nNot Eligible\n");
	   default:
	          printf("\nInvalid\n");
	}
    return 0;
}
