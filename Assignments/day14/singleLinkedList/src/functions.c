#include <header.h>

/*****************************************************
                   Local Functions
*****************************************************/
int create_node(Node **new_node, int data_len, char *id, int val);

/*****************************************************
                   Create Node Function
*****************************************************/
int create_node(Node **new_node, int data_len, char *id, int val)
{
    *new_node = (Node *)malloc(sizeof(Node));
    if (NULL == *new_node)
    {
        perror("error while creating node");
        return FAILURE;
    }

    (*new_node)->str = (char *)calloc(data_len, sizeof(char));
    if (NULL == (*new_node)->str)
    {
        perror("error while creating node, allocating memory for str");
        return FAILURE;
    }
    strcpy((*new_node)->id, id);
    (*new_node)->val = val;
    (*new_node)->next = NULL;
    return SUCCESS;
}

/*****************************************************
                   Insert at Beginning
*****************************************************/
int insert_at_beg(Node **head, char *str, char *id, int val)
{
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1, id, val))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);
    
    new_node->next = *head;
    *head = new_node;

    return SUCCESS;
}

/*****************************************************
                   Insert in Middle
*****************************************************/
int insert_in_middle(Node **head, char *str, char *after, char *id, int val)
{
    Node *tmp = NULL;
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1, id, val))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);

    if(NULL == *head)
    {
        *head = new_node;
        return SUCCESS;
    }

    tmp = *head;

    while (NULL != tmp->next)
    {
        if(!strcmp(tmp->str, after))
        {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return SUCCESS;
        }
        tmp = tmp->next;
    }

    tmp->next = new_node;

    return SUCCESS;
}

/*****************************************************
                   Insert at End
*****************************************************/
int insert_at_end(Node **head, char *str, char *id, int val)
{
    Node *tmp = NULL;
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1, id, val))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);
    
    if(NULL == *head)
    {
        *head = new_node;
        return SUCCESS;
    }

    tmp = *head;

    while (NULL != tmp->next)
    {
        tmp = tmp->next;
    }

    tmp->next = new_node;

    return SUCCESS;
}
/*****************************************************

    FUNCTION_NAME: myfflush
    
    DESCRIPTION:
        This function is a replacement of inbuilt
        function fflush(stdin)
    
    PARAMETERS:
        No parameters

    RETURN VALUE:
        It returns void

*****************************************************/
void myfflush(void)
{
    while('\n' != getchar());
}

/*****************************************************

    FUNCTION_NAME: get_string_input
    
    DESCRIPTION:
        This function reads a string from the stdin.
    
    PARAMETERS:
        Parameters are self descriptive.

    RETURN VALUE:
        It returns void

*****************************************************/
void get_string_input(char *input_string)
{
    while(1)
    {
        fgets(input_string, SIZE-1, stdin);
        int len = strlen(input_string);
        if (1 == len)
        {
            printf("\tempty string, enter again: ");
            memset(input_string, 0, SIZE);
            continue;
        }
        if ('\n' == input_string[len - 1])
        {
            input_string[len - 1] = '\0';
        }
        else
        {
            myfflush();
        }
        break;
    }
}
/*****************************************************
                   Display List
*****************************************************/
void display_list(Node *head)
{
    if (NULL == head)
    {
        printf("\tList is empty\n");
        return;
    }
    else
    {
        printf("\tElements in list are:\n");
    }
    while (head != NULL)
    {
        printf("\tID: %s, Value: %d, String: %s\n", head->id, head->val, head->str);
        head = head->next;
    }
}

/*****************************************************
                   Search and Update by Name
*****************************************************/
int search_update_name(Node **head, char *search, char *replace)
{
    Node *tmp = *head;

    while (tmp != NULL)
    {
        if (strcmp(tmp->str, search) == 0)
        {
            strcpy(tmp->str, replace);
            printf("\tNode updated: %s\n", replace);
            return SUCCESS;
        }
        tmp = tmp->next;
    }

    printf("\tNode with string \"%s\" not found.\n", search);
    return FAILURE;
}


int sorted_insert_name(Node **head, char *str, char *id, int val)
{
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1, id, val))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);

    // If list is empty or new node should be inserted at the beginning
    if (*head == NULL || strcmp((*head)->str, str) > 0)
    {
        new_node->next = *head;
        *head = new_node;
        return SUCCESS;
    }

    // Traverse the list and find the correct position
    Node *tmp = *head;
    while (tmp->next != NULL && strcmp(tmp->next->str, str) < 0)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
    return SUCCESS;
}

/*****************************************************
                   Insert Sorted by Value
*****************************************************/
int sorted_insert_val(Node **head, char *str, char *id, int val)
{
    Node *new_node = NULL;
    if (FAILURE == create_node(&new_node, strlen(str) + 1, id, val))
    {
        return FAILURE;
    }
    strcpy(new_node->str, str);

    // If list is empty or new node should be inserted at the beginning
    if (*head == NULL || (*head)->val > val)
    {
        new_node->next = *head;
        *head = new_node;
        return SUCCESS;
    }

    // Traverse the list and find the correct position
    Node *tmp = *head;
    while (tmp->next != NULL && tmp->next->val < val)
    {
        tmp = tmp->next;
    }

    new_node->next = tmp->next;
    tmp->next = new_node;
    return SUCCESS;
}

/*****************************************************
                   Delete Functions
*****************************************************/
int delete_at_beg(Node **head)
{
    Node *tmp = *head;

    if (NULL == tmp)
    {
        printf("\tList is empty, deletion failed\n");
        return FAILURE;
    }

    *head = (*head)->next;
    free(tmp->str);
    free(tmp);

    return SUCCESS;
}

int delete_in_middle(Node **head, char *str)
{
    Node *tmp = *head;

    if (NULL == tmp)
    {
        printf("\tList is empty, deletion failed\n");
        return FAILURE;
    }
    else
    {
        if (!strcmp(tmp->str, str))
        {
            *head = tmp->next;
            free(tmp->str);
            free(tmp);
            return SUCCESS;
        }
    }

    if (NULL == tmp->next)
    {
        printf("\t\"%s\" does not exist in the list\n", str);
        return FAILURE;
    }

    do
    {
        if (!strcmp(tmp->next->str, str))
        {
            Node *free_node = tmp->next;
            tmp->next = tmp->next->next;
            free(free_node->str);
            free(free_node);
            return SUCCESS;
        }
        tmp = tmp->next;
    } while (NULL != tmp->next);

    printf("\t\"%s\" does not exist in the list\n", str);
    return FAILURE;
}

int delete_at_end(Node **head)
{
    Node *tmp = *head;

    if (NULL == tmp)
    {
        printf("\tList is empty, deletion failed\n");
        return FAILURE;
    }

    if (NULL == tmp->next)
    {
        free(tmp->str);
        free(tmp);
        *head = NULL;
        return SUCCESS;
    }

    while (NULL != tmp->next->next)
    {
        tmp = tmp->next;
    }

    Node *free_node = tmp->next;
    tmp->next = NULL;
    free(free_node->str);
    free(free_node);

    return SUCCESS;
}

void free_list(Node **head)
{
    Node *tmp = *head;
    while (tmp != NULL)
    {
        Node *free_node = tmp;
        tmp = tmp->next;
        free(free_node->str);
        free(free_node);
    }
    *head = NULL;
}
