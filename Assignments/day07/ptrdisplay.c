#include <stdio.h>

void display(char *);

int main()
{
    char *arr = "hello hi";     
    char *ptr = arr;

    printf("sizeof(ptr): %lu, sizeof(arr): %lu\n", sizeof(ptr), sizeof(arr));
    display(ptr);

    return 0;
}

void display(char *ptr) 
{
    printf("\nAddress (ptr): 0x%p\n",(void *)ptr);
    printf("Contents (ptr): %s\n", ptr);
}
