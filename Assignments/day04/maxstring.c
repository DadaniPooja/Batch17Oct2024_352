#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[81];

    while (1) {
        printf("Enter a string (max 80 chars): ");
        fgets(str, sizeof(str), stdin);
        str[strcspn(str, "\n")] = '\0';

        if (strcmp(str, "END") == 0) {
            break;
        }

        for (int i = 0; str[i] != '\0'; i++) {
            str[i] = toupper(str[i]);
        }

        printf("Uppercase: %s\n", str);
    }

    printf("Program ended.\n");
    return 0;
}

