#ifndef STRUCT_H
#define STRUCT_H
#define OR ||
#define BUFF 1024
 
typedef struct Employee
{
    int id;
    int phno;
    int sal;
    char Name[50];
    char g;
}EMP;
 
int getDetails(EMP *, char []);
int printDetails(EMP *);
 
#endif
