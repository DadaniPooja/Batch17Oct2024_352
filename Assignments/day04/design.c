#include <stdio.h>

int main()
{
  int n;

  printf("2. Software Develope\n");
  printf("3. Senior Software Developer\n");
  printf("4. Team Lead\n");
  printf("5. Senior Team Lead\n");

  printf("Enter designation: ");
  scanf("%d",&n);

  switch(n)
  {
     case 2:
	        printf("Software Developer");
			break;
	 case 3:
	        printf("Senior Software Developer");
			break;
	 case 4:
	        printf("Team Lead");
			break;
	 case 5: 
	        printf("Senior Team Lead");
			break;
	 default:
	        printf("Incorrect Designation code");
  }
  printf("\n");
  return 0;
}

