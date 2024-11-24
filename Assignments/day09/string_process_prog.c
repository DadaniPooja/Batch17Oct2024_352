#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 80
#define FAILURE -1

int getFileString(char ***text, char *input) {
    FILE *fp;
    int textCount = 0, len = 0;
    char buff[MAX_SIZE];

    fp = fopen(input, "r");
    if (fp != NULL) {
        *text = (char **)malloc(sizeof(char *) * (MAX_SIZE + 1));
        if (*text != NULL) {
            while (fgets(buff, MAX_SIZE, fp) != NULL) {
                len = strlen(buff) + 1;
                (*text)[textCount] = (char *)malloc(sizeof(char) * len);
                if ((*text)[textCount] != NULL) {
                    strcpy((*text)[textCount], buff);
                    len -= 2;
                    if (((*text)[textCount])[len] == '\n') {
                        ((*text)[textCount])[len] = '\0';
                    }
                    textCount += 1;
                } else {
                    printf("\nNot able to allocate memory for string");
                    return FAILURE;
                }
            }
        } else {
            printf("\nNot able to allocate memory for text array");
            return FAILURE;
        }
        fclose(fp);
        return textCount;
    } else {
        printf("\nFile cannot be opened");
        return FAILURE;
    }
}

void display(char **arr, int num) {
    for (int i = 0; i < num; i++) {
        printf("%s\n", arr[i]);
    }
}

void freeMemory(char **arr, int num) {
    for (int i = 0; i < num; i++) {
        free(arr[i]);
    }
    free(arr);
}

int main(int argc, char *argv[]) {
    char **text = NULL;
    int textCount = 0;

    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return FAILURE;
    }

    textCount = getFileString(&text, argv[1]);
    if (textCount != FAILURE) {
        display(text, textCount);
        freeMemory(text, textCount);
    } else {
        printf("Error reading file.\n");
    }

    return 0;
}
