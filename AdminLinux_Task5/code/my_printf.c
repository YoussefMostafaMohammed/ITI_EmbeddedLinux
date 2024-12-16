#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void my_printf(int fd, const char *format, ...) {
    va_list args;
    va_start(args, format);

    const char *ptr = format;
    char buffer[1024];  // Buffer to hold the formatted string
    int i = 0;

    while (*ptr) {
        if (*ptr == '%' && *(ptr + 1)) {
            ptr++; // Move past '%'
            if (*ptr == 'd') {
                // Integer argument
                int value = va_arg(args, int);
                i += snprintf(buffer + i, sizeof(buffer) - i, "%d", value);
            } else if (*ptr == 's') {
                // String argument
                const char *str = va_arg(args, const char *);
                while (*str && i < sizeof(buffer) - 1) {
                    buffer[i++] = *str++;
                }
            } else {
                // Unknown format, just copy it
                buffer[i++] = '%';
                buffer[i++] = *ptr;
            }
        } else {
            // Normal character
            buffer[i++] = *ptr;
        }
        ptr++;
    }

    // Ensure null-termination
    buffer[i] = '\0';

    // Write the buffer to the given file descriptor
    write(fd, buffer, i);
    getchar();
    va_end(args);
}


int main() {
    int fd = 1;  // Standard output (stdout)
    my_printf(fd, "Hello, %s! The answer is %d.\n", "world", 42);
    return 0;
}

