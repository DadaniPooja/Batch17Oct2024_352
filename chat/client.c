#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 9000
#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define MAX_MESSAGE_LEN 256

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    char message[MAX_MESSAGE_LEN];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return 1;
    }

    printf("Welcome to the Multi-party Chat Client System!\n");
    printf("1. Register\n2. Login\nChoose an option: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
    // Register
    send(sockfd, "register", 8, 0);

    printf("Enter username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    printf("Enter password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    recv(sockfd, message, sizeof(message), 0);
    printf("Server: %s\n", message);

    // After registration is successful, no need to ask for login
    if (strcmp(message, "Registration successful! You are now logged in.") == 0) {
        // Proceed directly to the message sending phase
        while (1) {
            printf("Enter message: ");
            scanf(" %[^\n]", message);  // Read the message from the user

            send(sockfd, message, strlen(message), 0);  // Send the message to the server

            // Optionally, break the loop if user sends an exit message
            if (strcmp(message, "exit") == 0) {
                break;
            }

            // Receive server's confirmation
            recv(sockfd, message, sizeof(message), 0);
            printf("Server: %s\n", message);
        }
    }

} else if (choice == 2) {
    // Login
    send(sockfd, "login", 5, 0);

    printf("Enter username: ");
    scanf("%s", username);
    send(sockfd, username, strlen(username), 0);

    printf("Enter password: ");
    scanf("%s", password);
    send(sockfd, password, strlen(password), 0);

    recv(sockfd, message, sizeof(message), 0);
    printf("Server: %s\n", message);
}


    if (strcmp(message, "Login successful!") == 0) {
        // After successful login, start sending messages
        while (1) {
            printf("Enter message: ");
            scanf(" %[^\n]", message);  // Read the message from the user

            send(sockfd, message, strlen(message), 0);  // Send the message to the server

            // Optionally, break the loop if user sends an exit message
            if (strcmp(message, "exit") == 0) {
                break;
            }

            // Receive server's confirmation
            recv(sockfd, message, sizeof(message), 0);
            printf("Server: %s\n", message);
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}

