#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <ctype.h>

int validmail_count = 0;
pthread_mutex_t mutex;

int validate_email(char* email) {
    char* at_pos = strchr(email, '@');
    if (!at_pos) return 0;
    *at_pos = '\0';
    char* username = email;
    char* domain = at_pos + 1;
    if (isalpha(username[0]) && (strcmp(domain, "com") == 0 || strcmp(domain, "edu") == 0)) {
        return 1;
    }
    return 0;
}

void* email_validation_thread(void* arg) {
    char* email = (char*)arg;
    if (validate_email(email)) {
        pthread_mutex_lock(&mutex);
        validmail_count++;
        pthread_mutex_unlock(&mutex);
        return (void*)email;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <email1;email2;...>\n", argv[0]);
        return 1;
    }

    char* emails = argv[1];
    char* email = strtok(emails, ";");
    
    pthread_t thread;
    pthread_mutex_init(&mutex, NULL);

    while (email != NULL) {
        pthread_create(&thread, NULL, email_validation_thread, (void*)email);
        void* result;
        pthread_join(thread, &result);
        
        if (result != NULL) {
            printf("Valid email: %s\n", (char*)result);
        } else {
            printf("Invalid email: %s\n", email);
        }
        
        email = strtok(NULL, ";");
    }

    printf("Total valid emails: %d\n", validmail_count);
    pthread_mutex_destroy(&mutex);
    return 0;
}

