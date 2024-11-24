#include <header.h>

int main(int argc, char *argv[])
{
    Node *head = NULL;
    
    while (1)
    {
        system("clear");
        int choice = 0;
        char str[SIZE];
        char after[SIZE];
        char id[MAX_ID_LEN];
        int val;
        
        memset(str, 0, SIZE);
        memset(after, 0, SIZE);
       
        printf("\n**************Linked List Operation******************\n\n");
        printf("\t1. Insert at Beginning\n");
        printf("\t2. Insert after a Node\n");
        printf("\t3. Insert at End\n");
        printf("\t4. Delete at Beginning\n");
        printf("\t5. Delete a specified Node\n");
        printf("\t6. Delete at End\n");
        printf("\t7. Display\n");
        printf("\t8. Search and Update by Name\n");
		printf("\t9. Insert sorted by Name\n");
		printf("\t10. Insert sorted by Value\n");
        printf("\t11. Exit\n\n");
        printf("\tEnter your choice: ");
        scanf("%d", &choice);
        myfflush();

        switch(choice)
        {
            case 1:
                printf("\tEnter string: ");
                get_string_input(str);
                printf("\tEnter ID (max 5 chars): ");
                get_string_input(id);
                printf("\tEnter value: ");
                scanf("%d", &val);
                if (SUCCESS == insert_at_beg(&head, str, id, val))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 2:
                printf("\tEnter string: ");
                get_string_input(str);
                printf("\tEnter string after which you want to insert: ");
                get_string_input(after);
                printf("\tEnter ID (max 5 chars): ");
                get_string_input(id);
                printf("\tEnter value: ");
                scanf("%d", &val);
                if (SUCCESS == insert_in_middle(&head, str, after, id, val))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 3:
                printf("\tEnter string: ");
                get_string_input(str);
                printf("\tEnter ID (max 5 chars): ");
                get_string_input(id);
                printf("\tEnter value: ");
                scanf("%d", &val);
                if (SUCCESS == insert_at_end(&head, str, id, val))
                {
                    printf("\tInserted Successfully\n");
                }
                break;

            case 4:
                if (SUCCESS == delete_at_beg(&head))
                {
                    printf("\tDeleted Successfully\n");
                }
                break;

            case 5:
                printf("\tEnter string which you want to delete: ");
                get_string_input(str);
                if (SUCCESS == delete_in_middle(&head, str))
                {
                    printf("\tDeleted Successfully\n");
                }
                break;

            case 6:
                if (SUCCESS == delete_at_end(&head))
                {
                    printf("\tDeleted Successfully\n");
                }
                break;

            case 7:
                display_list(head);
                break;

            case 8:
                printf("\tEnter name to search and update: ");
                get_string_input(str);
                printf("\tEnter new name to replace: ");
                get_string_input(after);
                if (SUCCESS == search_update_name(&head, str, after))
                {
                    printf("\tUpdated Successfully\n");
                }
                break;
            
			case 9:
			    printf("\tEnter string: ");
                get_string_input(str);
                printf("\tEnter ID (max 5 chars): ");
                get_string_input(id);
                printf("\tEnter value: ");
                scanf("%d", &val);
                if (SUCCESS == sorted_insert_name(&head, str, id, val))
                {
                    printf("\tInserted Successfully in sorted order by name\n");
                }
                break;

            case 10:
			   printf("\tEnter string: ");
                get_string_input(str);
                printf("\tEnter ID (max 5 chars): ");
                get_string_input(id);
                printf("\tEnter value: ");
                scanf("%d", &val);
                if (SUCCESS == sorted_insert_val(&head, str, id, val))
                {
                    printf("\tInserted Successfully in sorted order by value\n");
                }
                break;

            case 11:
                free_list(&head);
                printf("\tExited\n");
                return SUCCESS;
     
            default:
                printf("\tWrong choice, try again\n");
                break;
        }
        printf("\n\tPress enter to continue...");
        myfflush();
    }
    return SUCCESS;
}
