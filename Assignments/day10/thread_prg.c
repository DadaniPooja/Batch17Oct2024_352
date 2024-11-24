#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *memory_leak(void *arg) {
    char *str = malloc(100);
    if (str == NULL) {
        return NULL;
    }
    printf("Thread processing\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, memory_leak, NULL);
    pthread_join(tid, NULL);
    return 0;
}
