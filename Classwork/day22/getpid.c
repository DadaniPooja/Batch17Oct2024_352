//process identification id

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   long int i;
   int pid = getpid();
   pid_t ppid = getppid();
   printf("My own id : %d\n",pid);
   printf("For %d parent is %d\n",pid,ppid);
   getchar();

   printf("\n");
   return 0;
}
