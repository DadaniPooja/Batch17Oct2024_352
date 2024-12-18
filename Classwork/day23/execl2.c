#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])   //pooja
{
  printf("\nec2\n");
  printf("\nPID : %d\n",getpid());
  printf("\n%s\n%s",argv[0],argv[1]);
  printf("\nHello, %s\n Welcome to the C programming\n",argv[1]);
  return 0;
}
