#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

void *thread1_func(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);  // Disable cancel
    while(1) {
        time_t t = time(NULL);
        printf("[%s] T1: Health OK\n", ctime(&t));
        sleep(2);
    }
    return NULL;
}

void *thread2_func(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);  // Enable cancel
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);  // Deferred cancel
    int count = 1000;
    while(1) {
        time_t t = time(NULL);
        printf("[%s] T2: %ld %d\n", ctime(&t), pthread_self(), count);
        count += 2;
        sleep(3);
    }
    return NULL;
}

void *thread3_func(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);  // Enable cancel
    pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);  // Asynchronous cancel
    int count = 2000;
    while(1) {
        time_t t = time(NULL);
        printf("[%s] T3: %ld %d\n", ctime(&t), pthread_self(), count);
        count += 2;
        sleep(3);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2, t3;
    
    pthread_create(&t1, NULL, thread1_func, NULL);
    pthread_create(&t2, NULL, thread2_func, NULL);
    pthread_create(&t3, NULL, thread3_func, NULL);

    sleep(180); // Wait for 3 minutes

    pthread_cancel(t1);  // Cancel T1
    pthread_cancel(t2);  // Cancel T2
    pthread_cancel(t3);  // Cancel T3

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);

    return 0;
}
   
