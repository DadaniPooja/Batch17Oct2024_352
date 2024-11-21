#include <stdio.h>

int fact(int);

int main()
{
  int n,s=0,i;
  printf("Enter range: \n");
  scanf("%d",&n);

  for(i=1;i<=n;i++)
  {
    s=s+fact(i);
	printf("%d!+",i);
  }
  printf("factorial is %d\n",s);
  return 0;
}

int fact(int n)
{
   int i,f=1;
   for(i=1;i<=n;i++)
       f=f*i;
   return f;
}
