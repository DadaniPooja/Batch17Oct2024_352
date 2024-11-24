#include <stdio.h>

typedef enum Designation
{
    E2F = 1,E2,E3,E4,E5
}DESG;

int main()
{
    int des;

    printf("Enter your designation: ");
    scanf("%d", &des);

    switch (des) {
        case E2F:
            printf("E2F Software Fresher\n");
            break;
        case E2:
            printf("E2 Software Engineer\n");
            break;
        case E3:
            printf("E3 Senior Software Engineer\n");
            break;
        case E4:
            printf("E4 Team Lead\n");
            break;
        case E5:
            printf("E5 Senior Team Lead\n");
            break;
        default:
            printf("Invalid designation entered.\n");
            break;
    }
    printf("\n");
    return 0;
}
