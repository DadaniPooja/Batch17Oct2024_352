#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************************************************************************
 *                  MACRO DECLARATIONS                                      *
 ***************************************************************************/
#define SUCCESS 1
#define FAILURE 0
#define END -1
#define MAX_QUEUE_SIZE 5  // Can be dynamically set at runtime

/* Data Type for Queue ADT */

typedef struct queue
{
    char **data;      // Dynamic array to store strings
    int front;
    int rear;
} queue_t;

/***************************************************************************
 *                  Function declarations                                    *
 ***************************************************************************/
void init_queue(queue_t *q, int capacity);
int check_empty(queue_t *q);
int check_full(queue_t *q);
int enqueue(queue_t *q, char *elem);
int dequeue(queue_t *q, char **p_elem);
void display(queue_t *q);

#endif
