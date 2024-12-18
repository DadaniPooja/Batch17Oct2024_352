#include "registration.h"

// Function to check if the username already exists in the user file
int is_username_taken(const char *username) {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        return 0;  // If the file doesn't exist, return false (no user yet)
    }

    char line[MAX_USERNAME_LEN + MAX_PASSWORD_LEN + 2];  // Space for usernam                                                                                e, password, and newline
    char stored_username[MAX_USERNAME_LEN];

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s", stored_username);
        if (strcmp(stored_username, username) == 0) {
            fclose(file);
            return 1;  // Username found, already taken
        }
    }

    fclose(file);
    return 0;  // Username not found, available
}

// Function to validate a user's login credentials
int validate_user(const char *username, const char *password) {
    FILE *file = fopen(USER_FILE, "r");
    if (!file) {
        return 0;  // If the file doesn't exist, return false (invalid)
    }

    char line[MAX_USERNAME_LEN + MAX_PASSWORD_LEN + 2];
    char stored_username[MAX_USERNAME_LEN], stored_password[MAX_PASSWORD_LEN]                                                                                ;

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s %s", stored_username, stored_password);
        if (strcmp(stored_username, username) == 0 && strcmp(stored_password,                                                                                 password) == 0) {
            fclose(file);
            return 1;  // Username and password match, valid user
        }
    }

    fclose(file);
    return 0;  // Invalid credentials
}

// Function to register a new user
int register_user(const char *username, const char *password) {
    if (is_username_taken(username)) {
        return 0;  // Username is already taken
    }

    FILE *file = fopen(USER_FILE, "a");
    if (!file) {
        perror("Unable to open user file");
        return 0;  // Failed to open file
    }

    fprintf(file, "%s %s\n", username, password);  // Store username and pass                                                                                word
    fclose(file);
    return 1;  // Registration successful
}

