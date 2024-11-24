#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define SUCCESS 1
#define FAILURE 0

typedef struct {
    char *name;
    int percentage;
} Student;

void input(char *str, Student **students, int *count);
void display(Student *students, int count);
void freeMem(Student *students, int count);
char* search_update(char *searchstr, char *replacestr);
int delete_record(Student **students, int *count, char *searchstr, int percent);
int copy(char *name, Student *students, int count, Student **newstudent);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <student_records>\n", argv[0]);
        return 1;
    }

    Student *students = NULL;
    int count = 0;

    input(argv[1], &students, &count);

    printf("No. of records: %d\n", count);
    display(students, count);

    // Example Usage of search_update
    char *updatedName = search_update("user1", "newUser1");
    printf("Updated Name: %s\n", updatedName);

    // Example Usage of delete_record
    if (delete_record(&students, &count, "user21", -1) == SUCCESS) {
        printf("Record with name 'user21' deleted.\n");
    }

    // Example Usage of copy
    Student *newStudent = NULL;
    if (copy("userABC", students, count, &newStudent) == SUCCESS) {
        printf("Successfully copied student record: %s, %d\n", newStudent->name, newStudent->percentage);
        free(newStudent->name);
        free(newStudent);
    }

    freeMem(students, count);

    return 0;
}

void input(char *str, Student **students, int *count) {
    char *token;
    const char *delim = ";";

    token = strtok(str, delim);
    while (token != NULL) {
        (*count)++;

        *students = realloc(*students, (*count) * sizeof(Student));
        if (*students == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }

        char *name = strtok(token, ",");
        char *perc = strtok(NULL, ",");
        if (name != NULL && perc != NULL) {
            (*students)[*count - 1].name = (char *)malloc(strlen(name) + 1);
            if ((*students)[*count - 1].name == NULL) {
                printf("Memory allocation failed for name.\n");
                exit(1);
            }
            strcpy((*students)[*count - 1].name, name);

            (*students)[*count - 1].percentage = atoi(perc);
        }

        token = strtok(NULL, delim);
    }
}

void display(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        printf("Record %d:\n", i + 1);
        printf("Name: %s, Percentage: %d\n", students[i].name, students[i].percentage);
    }
}

void freeMem(Student *students, int count) {
    for (int i = 0; i < count; i++) {
        free(students[i].name);
    }
    free(students);
}

char* search_update(char *searchstr, char *replacestr) {
    static char updatedName[MAX_NAME_LENGTH];
    if (strcmp(searchstr, "user1") == 0) {
        strcpy(updatedName, replacestr);
    } else {
        strcpy(updatedName, searchstr);
    }
    return updatedName;
}

int delete_record(Student **students, int *count, char *searchstr, int percent) {
    for (int i = 0; i < *count; i++) {
        if ((searchstr != NULL && strcmp((*students)[i].name, searchstr) == 0) || 
            (percent != -1 && (*students)[i].percentage == percent)) {
            free((*students)[i].name);
            for (int j = i; j < *count - 1; j++) {
                (*students)[j] = (*students)[j + 1];
            }
            (*count)--;
            *students = realloc(*students, (*count) * sizeof(Student));
            return SUCCESS;
        }
    }
    return FAILURE;
}

int copy(char *name, Student *students, int count, Student **newstudent) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, name) == 0) {
            *newstudent = (Student *)malloc(sizeof(Student));
            if (*newstudent == NULL) {
                printf("Memory allocation failed for new student.\n");
                return FAILURE;
            }

            (*newstudent)->name = (char *)malloc(strlen(students[i].name) + 1);
            if ((*newstudent)->name == NULL) {
                printf("Memory allocation failed for new student name.\n");
                return FAILURE;
            }
            strcpy((*newstudent)->name, students[i].name);
            (*newstudent)->percentage = students[i].percentage;
            return SUCCESS;
        }
    }
    return FAILURE;
}

