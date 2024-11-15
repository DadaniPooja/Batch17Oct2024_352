 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include<stdlib.h>
 #include<struct.h>
 int getDetails(EMP *e, char line[])
 {
         char *token = NULL;
         token = strtok(line,",");
         if(token != NULL)
         {
                 e->id = atoi(token);
                 token = strtok(NULL,",");
                 strcpy(e->Name,token);
                 token = strtok(NULL,",");
                 e->g = *token;
                 token = strtok(NULL,",");
                 e->phno = atoi(token);
                 token = strtok(NULL,",");
                 e->sal = atoi(token);
                 return 0;
         }
         return 1;
 }
 int printDetails(EMP *e)
 {
         printf("\n==========Employee Details are==========\n");
         printf("\nID: %d",e->id);
        printf("\nName: %s",e->Name);
         printf("\nGender: %c",e->g);
         printf("\nPhNo: %d",e->phno);
        printf("\nSalary: %d",e->sal);
         printf("\n========================================\n");
         printf("\n\n");
 }
