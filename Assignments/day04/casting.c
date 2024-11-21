#include <stdbool.h>
#include <stdio.h>

int main()
{
   int i = 123; 
   short s = 98; 
   bool b = true; 
   char c = 'Y'; 
   float d = 235.789; 
   
   printf("b+c= %c\n",b+c);
   printf("s * i= %d\n",s*i);
   printf("c = c+b = %c\n",c+b);
   printf("d = d+c = %.2f\n",d+c);
   printf("b= -d = %.2f\n",b-d);
   printf("\n");

   return 0;
}
