#include "header.h"

int main()
{
    queue_t q1;
    int option;
    int status; // success/failure return
    char elem[100]; // buffer to store user input string

    int queue_size;
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &queue_size);

    // Initialize the Queue with user-defined size
    init_queue(&q1, queue_size);

    // Main Input loop (or driver loop)
    while(1)
    {
        printf("Please enter your choice.\n");
        printf("1) Insert an element\n");
        printf("2) Remove an element\n");
        printf("3) Check Empty\n");
        printf("4) Check Full\n");
        printf("5) Debug Print the queue data\n");
        printf("6) Exit\n");
    
        scanf("%d", &option);

        switch (option)
        {
            case 1: /* Insert an element */
                    printf("Enter the string to insert: ");
                    getchar();  // to capture the newline character left by previous input
                    fgets(elem, sizeof(elem), stdin);
                    elem[strcspn(elem, "\n")] = 0; // Remove trailing newline

                    status = enqueue(&q1, elem);
                    if (SUCCESS == status)
                    {
                        printf(" Element inserted Successfully \n");
                    }
                    else
                    {
                        printf(" Queue full, cannot insert \n");
                    }
                    break;

            case 2: /* Remove the front element */
                    status = dequeue(&q1, *elem);
                    if (SUCCESS == status)
                    {
                        printf(" Element '%s' removed Successfully \n", elem);
                    }
                    else
                    {
                        printf(" Queue Empty, cannot remove \n");
                    }
                    break;
    
            case 3: /* Check Empty */
                    status = check_empty(&q1);
                    if (SUCCESS == status)
                    {
                        printf(" Queue is Empty \n");
                    }
                    else
                    {
                        printf(" Queue is not Empty \n");
                    }
                    break;

            case 4: /* Check Full */
                    status = check_full(&q1);
                    if (SUCCESS == status)
                    {
                        printf(" Queue is Full \n");
                    }
                    else
                    {
                        printf(" Queue is not Full \n");
                    }
                    break;

            case 5: /* Debug Print */ 
                    display(&q1);
                    break;

            case 6: /* Exit*/ 
                    exit(0);
                    break;
        }
    }
    exit(0);
}
