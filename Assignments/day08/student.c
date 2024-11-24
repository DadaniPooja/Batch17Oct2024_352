#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student 
{
           int id;
           char *name;
           int percentage;
};
 
void func(struct student *record);
char *read_update_name(char *);
int read_update_percentage(int *);

int main() 
{
          struct student record;
          record.name = (char *)malloc(sizeof(char)*50);
          record.id=1;
          strcpy(record.name, "Raju");
          record.percentage = 86.5;

		  read_update_name(record.name);
		  read_update_percentage(&record.percentage);
          func(&record);
		  free(record.name);
          return 0;
}
 
void func(struct student *record)
{
          printf(" Id is: %d \n", record->id);
          printf(" Name is: %s \n", record->name);
          printf(" Percentage is: %d \n", record->percentage);
}

char *read_update_name(char *name)
{
          printf("\nEnter name: ");
		  fgets(name,50,stdin);
		  name[strcspn(name,"\n")]='\0';
		  return name;
}

int read_update_percentage(int *percentage)
{
          printf("\nEnter percentage: ");
		  scanf("%d",percentage);
		  return *percentage;
}

