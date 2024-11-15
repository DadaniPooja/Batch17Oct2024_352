#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<struct.h>
int main(int argc,char *argv[])
{
 	int i;
	EMP *e=NULL;
	EMP *temp=NULL;
	FILE *fp;
	char *lines;
	char fileName[BUFF];
	if(argc>2 OR argc<2)
	{
		perror("\n File is missing\n:");
	}
	strcpy(fileName,argv[1]);
	fp=fopen(fileName,"r");
	if(fp == NULL)
	{
		perror("fopen: ");
		return 1;
	}
	printf("\n File open successfully");
	e = (EMP *)malloc(3*sizeof(EMP));
	temp = e;

	while((fgets(lines,BUFF,fp))!=NULL)
	{	getDetails(e,lines);
		e++;
	}
	e = temp;

	system("clear");
	for(i=0;i<3;i++,e++){
		printDetails(e);

	}
	printf("\n\n");
	return 0;
}
