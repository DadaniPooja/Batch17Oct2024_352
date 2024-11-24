#include <stdio.h>
#include <stdlib.h>
#include "fileop.h"

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_integer_file> <input_string_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *int_file = fopen(argv[1], "r");
    FILE *str_file = fopen(argv[2], "r");
    FILE *out_file = fopen(argv[3], "w");

    if (!int_file || !str_file || !out_file) {
        printf("Error opening files.\n");
        return 1;
    }

    merge_files(int_file, str_file, out_file);
    fclose(int_file);
    fclose(str_file);
    fclose(out_file);

    display_file(argv[3]);
    return 0;
}

