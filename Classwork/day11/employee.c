#include <stdio.h>
#include <string.h>

struct employee
{
   char fName[10];
   char lName[20];
   int eId;
   float eSal;
};

typedef struct employee EMP;

void getDetails(EMP [],int);
void dispDetails(EMP [],int);
void searchId(EMP [],int);
void searchlName(EMP [],int);
void searchSal(EMP [],int);
void updateFname(EMP [],int);

int main()
{
    int n,ch;
	printf("Enter number of records: ");
	scanf("%d",&n);
    EMP e[n];

    getDetails(e,n);
	
	while(1)
	{
	   printf("\n**********Menu**********\n");
	   printf("1.Display the Employee details\n");
	   printf("2.search Employee based on ID number\n");
	   printf("3.search employee based on Last Name\n");
	   printf("4.Search Employees who's Salary fall in between 6-10K\n");
	   printf("5.Update Employee record to change his/her lName\n");
	   printf("6.Exit\n");

	   printf("Enter choice: ");
	   scanf("%d",&ch);

	   switch(ch)
	   {
	     case 1: 
		        dispDetails(e,n);
                break;
		 case 2:
		        searchId(e,n);
				break;
		 case 3:
		        searchlName(e,n);
				break;
		 case 4:
		        searchSal(e,n);
				break;
		 case 5:
		        updateFname(e,n);
				break;
		 case 6:
		        printf("EXITING\n");
				break;
		 default:
		        printf("Invalid choice\n");
		}
	 }
   	return 0;
}

void  getDetails(EMP e[], int n)
{
    int i;

	printf("\nEnter Employee Details\n");
	for(i=0;i<n;i++)
	{
	    printf("\nEnter Employee %d details\n",i+1);
		printf("\nfName: ");
		scanf("%s",e[i].fName);
		printf("\nlName: ");
        scanf("%s",e[i].lName);
		printf("\nID: ");
		scanf("%d",&e[i].eId);
		printf("\nSalary: ");
		scanf("%f",&e[i].eSal);
	}
}

void dispDetails(EMP e[], int n)
{
	int i;
	printf("\nEmployee Details are\n");
	for(i=0;i<n;i++)
	{
		printf("\nID: %d",e[i].eId);
		printf("\nFirstName: %s",e[i].fName);
		printf("\nLastName: %s",e[i].lName);
		printf("\nSalary: %.2f\n",e[i].eSal);
	}
}

void searchId(EMP e[], int n)
{
    int k,i;
	printf("Enter the ID we want to search: ");
	scanf("%d",&k);

	for(i=0;i<n;i++)
	{
	    if(e[i].eId==k)
	       printf("Found\n");
		else
		   printf("Not found\n");
    }
}

void searchlName(EMP e[], int n)
{
    int i;
	char name[20];
    printf("\nEnter the Last Name you want to search: ");
	scanf("%s\n", name);
	for(i=0;i<n;i++)
	{
	   if(strcmp(e[i].lName, name) == 0)
	      printf("Found:\n ID: %d\nFirstName: %s\nLastName: %s\nSalary: %.2f\n",e[i].eId, e[i].fName, e[i].lName, e[i].eSal);
	}
}

void searchSal(EMP e[], int n)
{
     int i;
     printf("Employees salary between 6000 to 10000 are:\n");
	 for(i=0;i<n;i++)
	 {
	   if(e[i].eSal>=6000 && e[i].eSal<=10000)
	       printf("ID: %d\nFirstName: %s\nLastName: %s\nSalary: %.2f\n",e[i].eId, e[i].fName, e[i].lName, e[i].eSal);
     }
}

void updateFname(EMP e[], int n)
{
     int i,id;
     char name[10];
	 printf("Enter the Employee Id to update the First name:\n");
     scanf("%d\n", &id);
     for(i=0;i<n;i++)
     {
        if(e[i].eId == id)
		{
		   printf("Enter new First name: ");
		   scanf("%s\n",e[i].fName);
		   printf("Updated Name %s\n",e[i].fName);
        }
	 printf("Id not found to update\n");
	 }
}
