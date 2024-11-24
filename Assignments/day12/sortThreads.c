#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_LEN 100

void *sort_line(void *arg);
void display_sorted_lines(char **lines, int count);
void free_memory(char **lines, int count);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <line1> <line2> <line3>\n", argv[0]);
        return 1;
    }

    pthread_t threads[3];
    char *lines[3];
    for (int i = 0; i < 3; i++) {
        lines[i] = strdup(argv[i + 1]);
        pthread_create(&threads[i], NULL, sort_line, (void *)lines[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    display_sorted_lines(lines, 3);
    free_memory(lines, 3);

    return 0;
}

void *sort_line(void *arg) {
    char *line = (char *)arg;
    char *words[50];
    int count = 0;

    char *token = strtok(line, " ");
    while (token != NULL) {
        words[count++] = token;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                char *temp = words[i];
                words[i] = words[j];
                words[j] = temp;
            }
        }
    }

    char sorted_line[MAX_LEN] = "";
    for (int i = 0; i < count; i++) {
        strcat(sorted_line, words[i]);
        if (i < count - 1) strcat(sorted_line, " ");
    }

    strcpy(arg, sorted_line);
    return NULL;
}

void display_sorted_lines(char **lines, int count) {
    for (int i = 0; i < count; i++) {
        printf("Sorted Line %d: %s\n", i + 1, lines[i]);
    }
}

void free_memory(char **lines, int count) {
    for (int i = 0; i < count; i++) {
        free(lines[i]);
    }
}

