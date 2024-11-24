#include "header.h"

// Function to check if the queue is empty
int isempty(node *front) {
    return (front == NULL) ? SUCCESS : FAILURE;
}

// Function to insert a node in the queue
void enqueue(node **front, node **rear, int value, const char *str) {
    // Allocate memory for the new node
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL) {
        printf("Memory not available\n");
        exit(FAILURE);
    }

    // Assign integer data
    newnode->data = value;

    // Allocate memory for the string and copy the user input
    newnode->str_data = (char *)malloc((strlen(str) + 1) * sizeof(char));
    if (newnode->str_data == NULL) {
        printf("Memory not available for string\n");
        free(newnode); // Free the node memory if string allocation fails
        exit(FAILURE);
    }
    strcpy(newnode->str_data, str);

    // Set the next pointer to NULL
    newnode->next = NULL;

    // Insert at the rear of the queue
    if (isempty(*front)) {
        *front = newnode;
        *rear = newnode;
    } else {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

// Function to delete a node from the front of the queue
int dequeue(node **front, node **rear, int *value, char **str) {
    if (isempty(*front)) {
        printf("Queue Underflow\n");
        return FAILURE;
    }

    node *temp_node = *front;
    *value = temp_node->data;           // Get integer value
    *str = temp_node->str_data;         // Get string data

    // If only one node is present in the queue
    if (*front == *rear) {
        *front = NULL;
        *rear = NULL;
    } else {
        *front = (*front)->next;
    }

    free(temp_node->str_data);  // Free string data
    free(temp_node);            // Free the node itself
    return SUCCESS;
}

// Function to display the queue contents
void display(node *front) {
    if (isempty(front)) {
        printf("The Queue is empty\n");
        return;
    }

    node *current = front;
    printf("Queue contents:\n");
    while (current != NULL) {
        printf("Integer: %d, String: %s\n", current->data, current->str_data);
        current = current->next;
    }
}

// Function to free the memory of the entire queue
int free_queue(node *front, node *rear) {
    if (isempty(front)) {
        return FAILURE;
    }

    node *current = front;
    while (current != NULL) {
        node *next_node = current->next;
        free(current->str_data);  // Free the string data first
        free(current);            // Free the node memory
        current = next_node;
    }

    rear = NULL;
    return SUCCESS;
}
