#include <stdio.h>

int main()
{
   int n1,n2,n3,result;
   printf("Enter three numbers: ");
   scanf("%d%d%d",&n1,&n2,&n3);
   result=(n1<n2)?((n1<n3)?n1:n3):((n2<n3)? n2:n3);
   printf("\nThe smallest number is %d\n",result);
}
