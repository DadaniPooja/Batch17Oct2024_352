#include "registration.h"

int main() {
    int choice;

    // Infinite loop to keep prompting the user until they choose to exit
    while (1) {
        printf("\nWelcome to the Multi-party Chat Client System!\n");

        printf("1. Register\n");
        printf("2. Exit\n");

        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number (1 or 2).\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;  // Ask for input again
        }

        switch (choice) {
            case 1:
                prompt_user_for_registration();  // Register new user
                break;
            case 2:
                printf("Exiting program...\n");
                return 0;  // Exit program
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}

