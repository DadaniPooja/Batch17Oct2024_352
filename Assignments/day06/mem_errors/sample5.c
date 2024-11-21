/* A program to demonstrate "Still Reachable" leak.
  To see them, run valgrind with: --show-reachable=yes
*/

  
#include <stdio.h>

int main()
{
   FILE *fp;

   fp = fopen("test", "w");

   if (fp == NULL)
   {
        printf("Error : Unable to open file\n");
        return 1;
   }

  fprintf(fp, "hello world");

  return 0;

}
