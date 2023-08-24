#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define BUFF_SIZE 1024

void print_buffer(char buffer[], int *buff_ind);

int _printf(const char *format, ...) {
    int printed_characters = 0;
    va_list list;
    int buff_index = 0;
    char buffer[BUFF_SIZE];

    if (format == NULL) {
        return -1;
    }

    va_start(list, format);

    for (int num = 0; format && format[num] != '\0'; num++) {
        if (format[num] != '%') {
            buffer[buff_index++] = format[num];
            if (buff_index == BUFF_SIZE) {
                print_buffer(buffer, &buff_index);
            }
            printed_characters++;
        } else {
            print_buffer(buffer, &buff_index);
            num++; // Move to the next character after '%'
            if (format[num] == 'c') {
                char c = (char)va_arg(list, int);
                write(1, &c, 1);
                printed_characters++;
            } else if (format[num] == 's') {
                char *str = va_arg(list, char *);
                write(1, str, strlen(str));
                printed_characters += strlen(str);
            } else {
                write(1, &format[num - 1], 1); // Print the '%' character
                printed_characters++;
            }
        }
    }

    print_buffer(buffer, &buff_index);
    va_end(list);

    return printed_characters;
}

void print_buffer(char buffer[], int *buff_index) {
    if (*buff_index > 0) {
        write(1, buffer, *buff_index);
        *buff_index = 0;
    }
}

int main(void) {
    _printf("Hello, %c!\n", 'W');
    _printf("This is a %s.\n", "test");
    return 0;
}
