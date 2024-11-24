#include <stdio.h>
#include <stdarg.h>

void cmdlog(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(stdout, format, args);
    va_end(args);
}

int main() {
    int count = 10;
    char prefix = 'h';
    char label[] = "India";

    cmdlog("count:%d, prefix:%c, label:%s\n", count, prefix, label);

    return 0;
}
