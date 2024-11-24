#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int p_count = 0, np_count = 0;
pthread_mutex_t mtx;

int check_palindrome(char *s) {
    int len = strlen(s);
    for (int i = 0; i < len / 2; i++) {
        if (s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

void* proc_str(void *arg) {
    char *s = (char*)arg;
    int res = check_palindrome(s);
    char *msg = (char*)malloc(100 * sizeof(char));

    pthread_mutex_lock(&mtx);
    if (res) {
        p_count++;
        sprintf(msg, "%s is a palindrome", s);
    } else {
        np_count++;
        sprintf(msg, "%s is not a palindrome", s);
    }
    pthread_mutex_unlock(&mtx);

    return (void*)msg;
}

pthread_t* create_threads(int n) {
    pthread_t *t = (pthread_t*)malloc(n * sizeof(pthread_t));
    return t;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Provide at least 2 strings\n");
        return -1;
    }

    pthread_mutex_init(&mtx, NULL);

    int n = argc - 1;
    pthread_t *threads = create_threads(n);
    char **msgs = (char**)malloc(n * sizeof(char*));

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, proc_str, (void*)argv[i + 1]);
    }

    for (int i = 0; i < n; i++) {
        void *msg;
        pthread_join(threads[i], &msg);
        msgs[i] = (char*)msg;
    }

    for (int i = 0; i < n; i++) {
        printf("%s\n", msgs[i]);
        free(msgs[i]);
    }

    printf("Palindromes: %d\n", p_count);
    printf("Non-palindromes: %d\n", np_count);

    free(threads);
    free(msgs);
    pthread_mutex_destroy(&mtx);

    return 0;
}

