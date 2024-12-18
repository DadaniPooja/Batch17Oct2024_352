#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
   printf("I'm parent and my id is %d\n",getpid());//print the parent pid
   printf("\nParents PPID: %d\n",getppid());

   pid_t id=fork();

   if(id==0)
   {
      printf("\nI'm a child process\n");
	  printf("\nMy id = %d",getpid());

   }
   else
   {
     sleep(4);
	 //wait(4) //indefine type and will wait after killed
     printf("\nI'm a parent process PID: %d\n",getpid());
	 printf("\nParents PPID: %d",getppid());
	 printf("\nChilds Process id = %d",id);
   }

   printf("\nHello world %d\n",getppid());
   //printf("\nPID: %d\n",getpid()); //bash will become the parent now
   //printf("\nFork return id = %d\n",id);
   return 0;
}
