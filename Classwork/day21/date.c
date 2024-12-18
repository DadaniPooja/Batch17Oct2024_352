#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFF 1024

int compare(int month1,int month2,int day1,int day2,int year1,int year2)
{
    if(year1<year2)
            printf("E\n");
    else if(year1>year2)
            printf("L\n");
    else
    {
       if(month1<month2)
            printf("E\n");
       else if(month1>month2)
             printf("L\n");
       else
       {
          if(day1<day2)
              printf("E\n");
          else if(day1>day2)
              printf("L\n");
           else
              printf("S\n");
       }
   }
}

int main()
{
	int n=0;
	char date1[BUFF],date2[BUFF];
	int day1,day2,month1,month2,year1,year2;
	char *token=NULL;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s%s",date1,date2);
		
		token = strtok(date1,"/");
		month1 = atoi(token);
		token = strtok(NULL,"/");
		day1 = atoi(token);
		token = strtok(NULL,"/");
		year1 = atoi(token); 

		token = strtok(date2,"/");
		month2 = atoi(token);
		token = strtok(NULL,"/");
		day2 = atoi(token);
		token = strtok(NULL,"/");
		year2 = atoi(token); 		
        
        compare(month1,month2,day1,day2,year1,year2);	
	}
	return 0;
}
