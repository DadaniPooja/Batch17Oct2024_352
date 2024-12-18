#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 50
#define MAX_PASSWORD_LEN 50
#define USER_FILE "users.txt"

// Function to check if the username is already taken
int is_username_taken(const char *username);

// Function to validate the user's login details
int validate_user(const char *username, const char *password);

// Function to register a new user
int register_user(const char *username, const char *password);

#endif // REGISTRATION_H


