#include <stdio.h>
#include <stdlib.h>

typedef struct Employee
{
	int empID;
	char name[50];
	char desg[50];
	char gen;
	int sal;
	struct Employee *next; //Self referencial pointer (SELF/SRP)
}EMP;


EMP *createEmp(EMP *);
int dispMainMenu();
void printList(EMP *);
EMP *appendEmp(EMP *,EMP *);


int main()
{
	EMP *nn=NULL;
	EMP *head=NULL,*temp=NULL;
	int flag=0;
	int key=0;

	while(1)
	{
		switch(dispMainMenu())
		{
			case 1:
					nn = createEmp(nn);
					head = appendEmp(head,nn);
					break;
			case 2:
					printList(head);
					break;
			case 3:
			        searchEmp(head);
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

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		return;
	}
	printf("\nList is\n===================================\n");
	while(head)
	{
		printf("Employee ID: %d\nName: %s\nDesignation: %s\nGender: %c\nSalary: %d\n",head->empID,head->name,head->desg,head->gen,head->sal);
		head = head->next;	
	}
	printf("\n\n===================================\n");
}



EMP *appendEmp(EMP *head,EMP *nn)
{
	// printf("\nIn appendNode\n");
	EMP *temp = head;

	if(head == NULL)
	{
		//the list is empty
		printf("\nList is Empty\n");
		head = nn;
		temp = nn;
	}
	else
	{
		// printf("\nList is not empty\n");
		while(head->next!= NULL)
		{
			// printf("%d->",head->val);
			head = head->next;	
		}
		
		head->next = nn; //adding node to the end of the list
	}
	head = temp; //head is again pointed to the BA

	return head;
}

