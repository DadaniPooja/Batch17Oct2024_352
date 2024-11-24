#ifndef __HEADER__
#define __HEADER__

/***************************************************************************
                       STANDARD HEADER FILES
***************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/***************************************************************************
                       MACROS
***************************************************************************/
#define SIZE 25
#define MAX_ID_LEN 5

#define IN
#define OUT

#define TRUE 1
#define FALSE 0

#define SUCCESS 0
#define FAILURE 1
/***************************************************************************
                       STRUCTURES
***************************************************************************/
typedef struct Node
{
    char id[MAX_ID_LEN];  // ID with max length 5
    int val;               // Integer value
    char *str;             // String data
    struct Node *next;     // Pointer to next node
} Node;
/***************************************************************************
                       FUNCTION PROTOTYPES
***************************************************************************/
extern void myfflush(void);
extern void get_string_input(char *);

extern int insert_at_beg(Node **, char *, char *, int);
extern int insert_in_middle(Node **, char *, char *, char *, int);
extern int insert_at_end(Node **, char *, char *, int);

extern int delete_at_beg(Node **);
extern int delete_in_middle(Node **, char *str);
extern int delete_at_end(Node **);

extern void display_list(Node *);
extern void free_list(Node **);

extern int search_update_name(Node **, char *search, char *replace);
extern int sorted_insert_name(Node **, char *,char *,int);
extern int sorted_insert_val(Node **,char *,char *,int);

#endif
