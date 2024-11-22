#include <stdio.h>
#include <string.h>

#define MAX 100
#define SUCCESS 0
#define FAILURE 1

int append(char *, const char *);
void display(char *);

int main()
{
    char arr[MAX] = "Learning C";
    char *ptr = arr; 
    char appendstr[10] = "in my org";
    int ret;

    printf("Address of ptr before append: 0x%p\n", (void *)ptr);

    ret = append(ptr, appendstr);

    printf("Address of ptr after append: 0x%p\n", (void *)ptr);

    if(ret == SUCCESS) 
	{
        display(ptr);
	}

    return 0;
}

void display(char *ptr)
{
    printf("Address of ptr: 0x%p\n", (void *)ptr);
    printf("Contents: %s\n", ptr);
}

int append(char *arr, const char *appendstr) {
    while(*arr != '\0') {
        arr++;
    }

    while(*appendstr != '\0')
    {
        *arr = *appendstr;
        arr++;
        appendstr++;
    }
    *arr = '\0';
    return SUCCESS;
}

