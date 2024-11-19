#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>


void *func0()
{
	int i;
	int end = 10;
	for (i=0;i<end;i++)
	{
		printf("\n\ti=%d",i);
		sleep(1);
	}
}



void *func1()
{
	int i;
	int end = 15;
	for (i=0;i<end;i++)
	{
		printf("\n\ti=%d",i);
		sleep(2);
	}
}

int main()
{
	int i,end=10;
	pthread_t tid[2];
	printf("\nI am in Main\n");

	pthread_create(&tid[0],NULL,func0,NULL);
	pthread_create(&tid[1],NULL,func1,NULL);

	printf("\ntid[0]=%d",tid[0]);
	printf("\ntid[1]=%d",tid[1]);

	for (i=0;i<end;i++)
	{
		printf("\ni=%d",i);
		sleep(1);
	}
	
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);

	printf("\nProgram Ended\n\n");

	return 0;
	
}