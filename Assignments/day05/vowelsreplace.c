#include <stdio.h>
#include <string.h>
#include <ctype.h>

void replace_vowels(char *);

int main() {
    char word[41];    
    printf("Enter a word (max 40 characters): ");
    fgets(word, sizeof(word), stdin);
    
    word[strcspn(word, "\n")] = '\0';
    
    replace_vowels(word);
    
    printf("Updated word: %s\n", word);
    
    return 0;
}

void replace_vowels(char *word) {
    char temp[100];
    int i,j = 0;
    for ( i = 0; word[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", word[i])) {
            temp[j++] = 'a';
            temp[j++] = 'y';
        } else {
            temp[j++] = word[i];
        }
    }
    temp[j] = '\0';

    strcpy(word, temp);
}

