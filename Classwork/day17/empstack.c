#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct Employee
{
	int empID;
	char name[50];
	char desg[50];
	char gen;
	int sal;
	struct Employee *next; //Self referencial pointer (SELF/SRP)
}EMP;

int top;
int bottom=-1;

EMP *createEmp(EMP *);
int dispMainMenu();
void printList(EMP *);
void *pushEmp(EMP *,EMP *);
void *popEmp(EMP *);

int main()
{
	EMP *nn=NULL;
	EMP *head=NULL,*temp=NULL;
	int flag=0;
	top=bottom;

	while(1)
	{
		switch(dispMainMenu())
		{
			case 1:
					nn = createEmp(nn);
					head = pushEmp(head,nn);
					break;
			case 2:
					printList(head);
					break;
			case 3:
			        popEmp(head);
					break;
			case 4:
					flag = 1;
					break;
			default:
					printf("\nEnter the correct Choice");
					break;
		}
		if(flag == 1)
			break;
	}
	
	printf("\n\n");

	return 0;

}
EMP *createEmp(EMP *nn)
{
	nn = (EMP *)malloc(sizeof(EMP));
	printf("\nEnter employee ID: ");
	scanf("%d",&nn->empID);
    printf("\nEnter employee name: ");
    scanf("%s",nn->name);
	printf("\nEnter employee designation: ");
	scanf("%s",nn->desg);
	printf("\nEnter employee gender: ");
	scanf("%c",&nn->gen);
	printf("\nEnter empolyee salary: ");
	scanf("%d",&nn->sal);
	nn->next = NULL;
	return nn;
}


int dispMainMenu()
{
	int ch;
	printf("\nLinked List Menu\n");
	printf("\nPress,");
	printf("\n1. create record");
	printf("\n2. Add Employee");
	printf("\n3. display Employee");
	printf("\n4. Exit");
	printf("\nChoice: ");
	scanf("%d",&ch);

	return ch;
}


void printList(EMP *head)
{
    int i;
	if(top == bottom)
	{
		//the list is empty
		printf("\nstack is Empty\n");
		return;
	}
	printf("\nstack is\n");
	for(i=top;i>=0;i--)
	{
		printf("Employee ID: %d\nName: %s\nDesignation: %s\nGender: %c\nSalary: %d\n",head->empID,head->name,head->desg,head->gen,head->sal);
		head = head->next;	
	}
	printf("\n\n");
}



void *pushEmp(EMP *head,EMP *nn)
{
	// printf("\nIn appendNode\n");
	EMP *temp = head;

	if(top == MAX-1)
	{
		//the list is empty
		printf("\nstack is Empty\n");
		return;
	}
	head[++top]=nn;
}

void popEmp(EMP *head)
{
    if(top==bottom)
	{
	   printf("\nstack is empty\n");
	   return;
	}
	printf("\npopped out\n");
	top--;
}
