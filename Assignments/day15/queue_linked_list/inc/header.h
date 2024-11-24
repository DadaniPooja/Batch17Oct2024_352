#ifndef __HEADER__
#define __HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Macro definitions
#define SUCCESS 1
#define FAILURE 0
#define MAX_STRING_LENGTH 80  // Max string length

// Node structure for the queue
typedef struct node_q {
    int data;            // Integer data
    char *str_data;      // String data read from user
    struct node_q *next; // Pointer to next node
} node;

// Function declarations
void enqueue(node **front, node **rear, int value, const char *str);
int dequeue(node **front, node **rear, int *value, char **str);
int isempty(node *front);
void display(node *front);
int free_queue(node *front, node *rear);

#endif
