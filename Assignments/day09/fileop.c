#include <stdio.h>
#include <stdlib.h>
#include "fileop.h"

void merge_files(FILE *int_file, FILE *str_file, FILE *out_file) {
    int num;
    char line[256];
    
    while (fscanf(int_file, "%d", &num) == 1 && fgets(line, sizeof(line), str_file)) {
        fprintf(out_file, "%d%s", num, line);
    }
}

void display_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error opening file for display.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

