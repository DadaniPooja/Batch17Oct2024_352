#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 51

typedef enum
{
    INTERN,
    JUNIOR,
    SENIOR,
    MANAGER
} Designation;

typedef struct
{
    char name[MAX];
    unsigned int age;
    Designation designation;
} EMP;

void read(EMP *emp)
{
    printf("Enter name: ");
    fgets(emp->name, MAX, stdin);
    emp->name[strcspn(emp->name, "\n")] = '\0';

    printf("Enter age: ");
    scanf("%u", &emp->age);

    printf("Enter designation: ");
    int desg;
    scanf("%d", &desg);
    emp->designation = (Designation)desg;

    while (getchar() != '\n');
}

void display(EMP emp)
{
    printf("\n Employee details:/n");
    printf("Name: %s\n", emp.name);
    printf("Age: %u\n", emp.age);
    printf("Designation: ");
    switch (emp.designation)
        {
        case INTERN: 
		           printf("INTERN\n"); 
		           break;
        case JUNIOR:
		           printf("JUNIOR\n");
				   break;
        case SENIOR:
		           printf("SENIOR\n");
				   break;
        case MANAGER:
		           printf("MANAGER\n");
				   break;
	    default:
		      printf("\nEnter valid designationc\n");
			  break;
    }
}


int update(EMP *emp)
{
    printf("Update employee details\n");
    read(emp);
    return 0;
}

EMP copy(EMP emp)
{
    EMP new_emp;
    strcpy(new_emp.name, emp.name);
    new_emp.age = emp.age;
    new_emp.designation = emp.designation;
    return new_emp;
}

int main()
{
    EMP employees[3];

    for (int i = 0; i < 3; i++)
        {
        printf("\nEnter details for employee %d:\n", i + 1);
        read(&employees[i]);
    }

    printf("\nEmployee details:\n");
    for (int i = 0; i < 3; i++)
        {
        printf("\nEmployee %d:\n", i + 1);
        display(employees[i]);
    }

    return 0;
}

