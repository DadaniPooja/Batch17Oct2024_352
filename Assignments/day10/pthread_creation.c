#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <ctype.h>

void *count_words(void *);
void *count_chars(void *);
void *process_text(void *);

void *count_words(void *input_str) {
    char *str = (char *)input_str;
    int word_count = 0;
    char *token = strtok(str, " \t\n");

    while (token != NULL) {
        word_count++;
        token = strtok(NULL, " \t\n");
    }

    int *result = malloc(sizeof(int));
    *result = word_count;
    return result;
}

void *count_chars(void *input_str) {
    char *str = (char *)input_str;
    int char_count = 0;

    while (*str) {
        if (!isspace(*str)) {
            char_count++;
        }
        str++;
    }

    int *result = malloc(sizeof(int));
    *result = char_count;
    return result;
}

void *process_text(void *input_str) {
    char *text = (char *)input_str;
    pthread_t t1, t2;
    void *words, *chars;

    pthread_create(&t1, NULL, count_words, text);
    pthread_create(&t2, NULL, count_chars, text);

    pthread_join(t1, &words);
    pthread_join(t2, &chars);

    printf("Words: %d\n", *(int *)words);
    printf("Chars: %d\n", *(int *)chars);

    free(words);
    free(chars);

    return NULL;
}

int main() {
    char text[256];

    printf("Enter text: ");
    fgets(text, 256, stdin);

    pthread_t main_thread;
    pthread_create(&main_thread, NULL, process_text, text);
    pthread_join(main_thread, NULL);

    return 0;
}

