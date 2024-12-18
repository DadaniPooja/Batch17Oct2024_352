#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "registration.h"

#define PORT 9000
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_MESSAGE_LEN 256

typedef struct {
    int sockfd;
    char username[MAX_USERNAME_LEN];
} client_t;

// Function to handle each client connection
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    char buffer[MAX_MESSAGE_LEN];

    // Receive choice for registration or login
    recv(client->sockfd, buffer, sizeof(buffer), 0);

    if (strcmp(buffer, "register") == 0) {
        // Handle registration
        recv(client->sockfd, username, sizeof(username), 0);
        recv(client->sockfd, password, sizeof(password), 0);

        // Store the username in the client struct
        strncpy(client->username, username, MAX_USERNAME_LEN);

        if (register_user(username, password)) {
            snprintf(buffer, sizeof(buffer), "Registration successful! You are now logged in.");
            send(client->sockfd, buffer, strlen(buffer), 0);

            // Proceed directly to message sending phase
            while (1) {
                int bytes_received = recv(client->sockfd, buffer, MAX_MESSAGE_LEN, 0);
                if (bytes_received <= 0) {
                    break;  // Exit if the client disconnects
                }
                buffer[bytes_received] = '\0';  // Null-terminate the string

                // Display message on server with correct username
                printf("Server: Received message from '%s': %s\n", client->username, buffer);

                // Respond to client with confirmation
                send(client->sockfd, "Message received.", 17, 0);
            }

            // When the client exits
            printf("Server: Client '%s' exited the chat.\n", client->username);
            close(client->sockfd);
            free(client);
            return NULL;

        } else {
            snprintf(buffer, sizeof(buffer), "Username already taken.");
            send(client->sockfd, buffer, strlen(buffer), 0);
            close(client->sockfd);
            free(client);
            return NULL;
        }

    } else if (strcmp(buffer, "login") == 0) {
        // Handle login
        recv(client->sockfd, username, sizeof(username), 0);
        recv(client->sockfd, password, sizeof(password), 0);

        // Store the username in the client struct
        strncpy(client->username, username, MAX_USERNAME_LEN);

        if (validate_user(username, password)) {
            snprintf(buffer, sizeof(buffer), "Login successful!");
            send(client->sockfd, buffer, strlen(buffer), 0);

            // Proceed to message sending phase
            while (1) {
                int bytes_received = recv(client->sockfd, buffer, MAX_MESSAGE_LEN, 0);
                if (bytes_received <= 0) {
                    break;  // Exit if the client disconnects
                }
                buffer[bytes_received] = '\0';  // Null-terminate the string

                // Display message on server with correct username
                printf("Server: Received message from '%s': %s\n", client->username, buffer);

                // Respond to client with confirmation
                send(client->sockfd, "Message received.", 17, 0);
            }

            // When the client exits
            printf("Server: Client '%s' exited the chat.\n", client->username);
            close(client->sockfd);
            free(client);
            return NULL;

        } else {
            snprintf(buffer, sizeof(buffer), "Invalid username or password.");
            send(client->sockfd, buffer, strlen(buffer), 0);
            close(client->sockfd);
            free(client);
            return NULL;
        }
    }

    return NULL;
}



int main() {
    int server_fd, new_client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    pthread_t tid;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_fd, 10) < 0) {
        perror("Listen failed");
        return 1;
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        // Accept client connections
        new_client_sock = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (new_client_sock < 0) {
            perror("Accept failed");
            continue;
        }

        // Create a new thread for each client
        client_t *client = (client_t *)malloc(sizeof(client_t));
        client->sockfd = new_client_sock;
        pthread_create(&tid, NULL, handle_client, (void *)client);
    }

    return 0;
}

