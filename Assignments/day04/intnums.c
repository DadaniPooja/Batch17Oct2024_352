#include <stdio.h>

int nums(int);

int main()
{
   int n;
   printf("Enter range\n");
   scanf("%d",&n);
   nums(n);
   return 0;
}

int nums(int n)
{
  int i,a[n],pcnt=0,ncnt=0,zcnt=0;
  printf("\nEnter numbers: ");
  for(i=0;i<n;i++)
     scanf("%d",&a[i]);
  for(i=0;i<n;i++)
  {
    if(a[i]>0)
	   pcnt++;
	else if(a[i]<0)
	   ncnt++;
	else
	   zcnt++;
  }
  printf("\n%d positive numbers\n",pcnt);
  printf("%d negative numbers\n",ncnt);
  printf("%d zero numbers\n",zcnt);
  return 0;
}

