#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
  printf("\nThis is Program\n");
  if(fork()>0)
  {
      wait(0);
	  printf("\nProgram PID: %d",getpid());
  }
  else
     execl("/usr/bin/ls","/usr/hin/ls",(char *)0);
  printf("\nEnding program\n");
  return 0;
}
