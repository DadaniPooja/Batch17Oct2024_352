#include "header.h"

int main(void) {
    node *front = NULL, *rear = NULL;
    int status, value;
    char input_string[MAX_STRING_LENGTH]; 
    char *str = NULL;

    while (1) {
        printf("\n1.Insert\n2.Remove\n3.Display\n4.Exit\n");
        int choice;
        scanf("%d", &choice);
        getchar(); 
        switch (choice) {
            case 1: 
                printf("Enter an integer value: ");
                scanf("%d", &value);
                getchar(); 
                printf("Enter a string (max %d characters): ", MAX_STRING_LENGTH);
                fgets(input_string, sizeof(input_string), stdin);
                input_string[strcspn(input_string, "\n")] = '\0'; 
                enqueue(&front, &rear, value, input_string);
                break;

            case 2: 
                status = dequeue(&front, &rear, &value, &str);
                if (status == SUCCESS) {
                    printf("Element removed: Integer = %d, String = %s\n", value, str);
                    free(str);  
                }
                break;

            case 3: 
                display(front);
                break;

            case 4: 
                status = free_queue(front, rear);
                if (status == SUCCESS) {
                    printf("Memory freed.\n");
                } else {
                    printf("Queue was already empty.\n");
                }
                exit(0);
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}
