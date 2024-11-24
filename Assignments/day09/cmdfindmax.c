#include <stdio.h>
#include <stdarg.h>
#include <string.h>

char* max_len_string(int count, ...) {
    va_list args;
    va_start(args, count);

    char *max_str = va_arg(args, char*);
    int max_len = strlen(max_str);

    for (int i = 1; i < count; i++) {
        char *current_str = va_arg(args, char*);
        int current_len = strlen(current_str);
        if (current_len > max_len) {
            max_str = current_str;
            max_len = current_len;
        }
    }

    va_end(args);
    return max_str;
}

int main() {
    char *ptr = max_len_string(5, "hi", "hello", "How", " Are", "END");
    printf("%s", ptr);

    return 0;
}

