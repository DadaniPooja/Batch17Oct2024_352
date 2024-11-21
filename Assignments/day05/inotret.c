#include <stdio.h>
#define MAX 100

void init(int [],int,int);
void update(int [],int);
void display(int [],int);

int main()
{
  int a[MAX]={11,22,33};
  int i,c=0,start;

 for(i=0;i<MAX;i++)
 {
    if(a[i]==0)
	   break;
	c++; 
 }

 printf("Enter starting value : ");
 scanf("%d",&start);

 init(a,c,start);
 display(a,c);
 update(a,c);
 display(a,c);

 return 0;
}

void init(int a[],int c,int start)
{
   int i;
   for(i=0;i<c;i++)
   {
     a[i]=start+i;
   }
}

void display(int a[],int c)
{
   int i;
   for(i=0;i<c;i++)
   {
      printf("%d ",a[i]);
   }
   printf("\n");
}

void update(int a[],int c)
{
  int i;
  for(i=0;i<c;i++)
  {
    a[i]++;
  }
}


