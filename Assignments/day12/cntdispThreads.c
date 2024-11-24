#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

typedef struct {
    char line[MAX_LINE_LENGTH];
    int word_count;
} LineData;

pthread_t *createthreads(int thread_count);
void process_file(const char *filename, pthread_t *threads, int thread_count);
void *thread_proc(void *arg);
int count_words(char *line);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    int thread_count = 0;
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)) {
        thread_count++;
    }
    fclose(file);

    pthread_t *threads = createthreads(thread_count);
    process_file(argv[1], threads, thread_count);

    free(threads);
    return 0;
}

pthread_t *createthreads(int thread_count) {
    pthread_t *threads = (pthread_t *)malloc(thread_count * sizeof(pthread_t));
    if (threads == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    return threads;
}

void process_file(const char *filename, pthread_t *threads, int thread_count) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    for (int i = 0; i < thread_count; i++) {
        if (fgets(line, MAX_LINE_LENGTH, file)) {
            LineData *data = (LineData *)malloc(sizeof(LineData));
            strcpy(data->line, line);
            pthread_create(&threads[i], NULL, thread_proc, data);
        }
    }

    for (int i = 0; i < thread_count; i++) {
        void *result;
        pthread_join(threads[i], &result);
        LineData *data = (LineData *)result;
        printf("Line: %sWord count: %d\n", data->line, data->word_count);
        free(data);
    }

    fclose(file);
}

void *thread_proc(void *arg) {
    LineData *data = (LineData *)arg;
    data->word_count = count_words(data->line);
    return data;
}

int count_words(char *line) {
    int count = 0;
    char *token = strtok(line, " \t\n");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " \t\n");
    }
    return count;
}

