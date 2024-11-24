#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *read_username(void *arg) {
    char *username = (char *)malloc(50 * sizeof(char));
    if (username == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    printf("Enter username: ");
    fgets(username, 50, stdin);
    return username;
}

int main() {
    pthread_t tid;
    void *result;

    pthread_create(&tid, NULL, read_username, NULL);

    pthread_join(tid, &result);

    printf("Username entered: %s", (char *)result);
    free(result);

    printf("Parent thread ID: %lu\n", pthread_self());
    printf("Child thread ID: %lu\n", tid);

    return 0;
}
