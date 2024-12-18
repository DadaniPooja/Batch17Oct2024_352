#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
   char *temp[5][1024]; // allocating memory
   
   for(int i=0;i<5;i++)
      temp[i]=(char *)malloc(1024);

   if(strcmp(argv[1],"calc")=0)
   {
     strcpy(temp[0],argv[1]);
     strcpy(temp[1],argv[2]); //+
     strcpy(temp[2],argv[3]);
     strcpy(temp[3],argv[4]);
     temp[4]=(char *)0;
   }
  /* else if(strcmp(argv[1],"area")==0)
   {
     strcpy(temp[0],argv[1]);
     strcpy(temp[1],argv[2]); //+
     strcpy(temp[2],argv[3]);
     strcpy(temp[3],argv[4]);
     temp[4]=(char *)0;
   }*/
   execv(argv[1],temp);// even this path name want to taken as argrument then we do argv[1]
   printf("\nThis line will not print\n");
   return 0;
}

