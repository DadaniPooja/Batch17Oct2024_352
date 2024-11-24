#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_WORDS 5
#define MAX_LENGTH 100

void *process_word(void *arg);
void wait_for_threads(pthread_t *threads, void **results, int num_threads);

void *process_word(void *arg) {
    char *word = (char *)arg;
    char *modified_word = malloc(strlen(word) + 4); // "_ed" added
    if (modified_word) {
        strcpy(modified_word, word);
        strcat(modified_word, "_ed");
    }
    return modified_word;
}

void wait_for_threads(pthread_t *threads, void **results, int num_threads) {
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], &results[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > MAX_WORDS + 1) {
        printf("Please enter between 1 and 5 words.\n");
        return 1;
    }

    pthread_t threads[MAX_WORDS];
    void *results[MAX_WORDS];
    int num_threads = argc - 1;

    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, process_word, argv[i + 1]);
    }

    wait_for_threads(threads, results, num_threads);

    for (int i = 0; i < num_threads; i++) {
        printf("Thread %d: %s\n", i + 1, (char *)results[i]);
        free(results[i]);
    }
    return 0;
}

