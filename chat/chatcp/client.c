#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"
#define MAX_RETRY_ATTEMPTS 5
#define TIMEOUT_SEC 5

// Session structure
typedef struct {
    int socket_fd;
    char session_id[64];
} ClientSession;

// Function to generate a new session ID
void generate_session_id(char *session_id) {
    snprintf(session_id, 64, "session-%ld", time(NULL));
}

// Function to create and connect a socket
int create_connection(const char *server_addr, int port) {
    struct sockaddr_in server_addr_in;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    memset(&server_addr_in, 0, sizeof(server_addr_in));
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(port);

    if (inet_pton(AF_INET, server_addr, &server_addr_in.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }
    if (connect(sockfd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) < 0) {
        perror("Connection failed");
        return -1;
    }

    return sockfd;
}

// Function to clear the input buffer (to fix the prompt issue)
void clear_input_buffer() {
    while (getchar() != '\n');  // Clear the input buffer
}

// Function to maintain active session
int maintain_active_session(ClientSession *session) {
    int retry_attempts = 0;

    while (retry_attempts < MAX_RETRY_ATTEMPTS) {
        // Try to connect
        printf("Attempting to connect... (Attempt %d)\n", retry_attempts + 1);

        session->socket_fd = create_connection(SERVER_ADDR, SERVER_PORT);

        if (session->socket_fd < 0) {
            retry_attempts++;
            printf("Connection failed, retrying in %d seconds...\n", TIMEOUT_SEC);
            sleep(TIMEOUT_SEC);
        } else {
            printf("Connected successfully, session ID: %s\n", session->session_id);
            return 1; // Successfully connected
        }
    }

    // If we reached the max retry attempts, return failure
    printf("Max retry attempts reached. Exiting...\n");
    return 0;
}

// Function to handle server communication
void communicate_with_server(int sockfd) {
    char buffer[1024];
    while (1) {
        printf("Enter message to send to server: ");
        fgets(buffer, sizeof(buffer), stdin);
        
        // Remove the newline character if present
        buffer[strcspn(buffer, "\n")] = 0;

        // Send the message to the server
        send(sockfd, buffer, strlen(buffer), 0);

        if (strstr(buffer, "exit") != NULL) {
            char choice;
            // Prompt user whether to reconnect or exit
            printf("Do you want to reconnect or exit the chat? (r/e): ");
            scanf(" %c", &choice);  // Space before %c to capture any whitespace
            clear_input_buffer();  // Clear the remaining newline character from buffer

            if (choice == 'r' || choice == 'R') {
                printf("Reconnecting...\n");

                // Close the old socket
                close(sockfd);

                // Generate a new session ID
                char new_session_id[64];
                generate_session_id(new_session_id);
                printf("Generated new Session ID: %s\n", new_session_id);

                // Create a new session and try to reconnect
                ClientSession new_session;
                strncpy(new_session.session_id, new_session_id, sizeof(new_session.session_id));
                if (maintain_active_session(&new_session)) {
                    // Re-enter the message communication loop after reconnecting
                    communicate_with_server(new_session.socket_fd);
                    return; // Exit the current function, but continue to handle communication
                }
            } else if (choice == 'e' || choice == 'E') {
                printf("Exiting chat...\n");
                close(sockfd);  // Close the socket
                exit(EXIT_SUCCESS);  // Exit cleanly
            } else {
                printf("Invalid choice, please enter 'r' to reconnect or 'e' to exit.\n");
            }
        }
    }
}

// Main function that manages session and communication
int main() {
    srand(time(NULL));  // Seed for random disconnection simulation

    ClientSession session;
    char new_session_id[64];

    // Step 1: Generate a new session ID
    generate_session_id(session.session_id);
    printf("Generated Session ID: %s\n", session.session_id);

    // Step 2: Try to establish a connection to the server
    if (maintain_active_session(&session)) {
        // Step 3: Simulate server communication (can be sending/receiving data)
        communicate_with_server(session.socket_fd);
    }

    // Cleanup
    close(session.socket_fd);
    return 0;
}

