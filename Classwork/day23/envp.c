#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[],char *envp[])
{
   int i;
   char *temp;
   for(i=0;envp[i];i++)
   {
      printf("%s\n",envp[i]);
   }
   printf("\n");
   return 0;
}
