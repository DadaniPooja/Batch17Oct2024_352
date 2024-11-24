#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 80

int write(FILE *fptr, char *line);
int read(FILE *fptr, char *linebuf);

int main(int argc, char *argv[]) {
    char *input, line1[MAX], line2[MAX];
    FILE *fptr;
    
    if (argc != 2) {
        printf("Usage: %s <line1;line2>\n", argv[0]);
        return 1;
    }

    input = argv[1];

    if (sscanf(input, "%79[^;];%79[^\n]", line1, line2) != 2) {
        printf("Invalid input format. Please provide two lines separated by a semicolon.\n");
        return 1;
    }

    fptr = fopen("fout.txt", "w");
    if (fptr == NULL) {
        printf("Unable to open file for writing.\n");
        return 1;
    }

    if (!write(fptr, line1) || !write(fptr, line2)) {
        printf("Error writing to file.\n");
        fclose(fptr);
        return 1;
    }

    fclose(fptr);

    fptr = fopen("fout.txt", "r");
    if (fptr == NULL) {
        printf("Unable to open file for reading.\n");
        return 1;
    }

    char linebuf[MAX];
    while (read(fptr, linebuf)) {
        printf("%s", linebuf);
    }

    fclose(fptr);

    return 0;
}

int write(FILE *fptr, char *line) {
    if (fptr == NULL || line == NULL) {
        return 0;
    }
    fprintf(fptr, "%s\n", line);
    return 1;
}

int read(FILE *fptr, char *linebuf) {
    if (fptr == NULL || linebuf == NULL) {
        return 0;
    }
    if (fgets(linebuf, MAX, fptr) == NULL) {
        return 0;
    }
    return 1;
}

