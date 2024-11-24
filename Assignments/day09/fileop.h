#ifndef FILEOP_H
#define FILEOP_H

#include <stdio.h>

void merge_files(FILE *int_file, FILE *str_file, FILE *out_file);
void display_file(const char *filename);

#endif

