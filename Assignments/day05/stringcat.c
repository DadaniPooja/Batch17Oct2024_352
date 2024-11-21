#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *my_strncat(char *, const char *, int);

int main() {
    char d[100] = "Hello, ";
    char s[] = "world!";
    
    my_strncat(d, s, 3);
    
    printf("Concatenated String: %s\n", d);
    
    return 0;
}

char *my_strncat(char *d, const char *s, int n) {
    int i;
    while (*d != '\0') {
        d++;
    }

    while (i<n) {
        *d = *s;
        d++;
        s++;
        i++;
    }
    *d = '\0';

    return d;
}
