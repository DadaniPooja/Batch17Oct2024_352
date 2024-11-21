#include <stdio.h>
#include <string.h>

int tokenise(char *);

int main() {
    char str[100];
    int n;

    printf("Enter a line of text: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = '\0';
    
    n = tokenise(str);
    printf("Total number of tokens: %d\n", n);
    
    return 0;
}

int tokenise(char *arr) {
    int c = 0;
    char *token = strtok(arr, " ");

    while (token != NULL) {
        printf("Token: %s\n", token);
        c++;
        token = strtok(NULL, " ");
    }
    return c;
}

