#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

// Function to handle client communication
void *handle_client(void *client_socket) {
    int client_sock = *(int *)client_socket;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_received;

    printf("New client connected\n");

    // Loop to communicate with the client
    while ((bytes_received = recv(client_sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null-terminate received string
        printf("Received from client: %s\n", buffer);

        // Send a response back to the client
        send(client_sock, "Message received\n", 18, 0);

        // If client sends "exit", close the connection
        if (strstr(buffer, "exit") != NULL) {
            printf("Client requested disconnect. Closing connection.\n");
            break;
        }
    }

    close(client_sock);
    printf("Client disconnected\n");
    return NULL;
}

int main() {
    int server_fd, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
 pthread_t thread_id;

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        return -1;
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        return -1;
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    // Accept and handle incoming client connections
    while (1) {
        if ((client_sock = accept(server_fd, (struct sockaddr *)&client_addr, &addr_len)) == -1) {
            perror("Accept failed");
            continue;
        }

        // Create a new thread for each client
        if (pthread_create(&thread_id, NULL, handle_client, (void *)&client_sock) != 0) {
            perror("Thread creation failed");
            continue;
        }

        // Detach the thread so it cleans up after itself
        pthread_detach(thread_id);
    }

    // Cleanup (although it never reaches here in the current infinite loop)
    close(server_fd);
    return 0;
}

