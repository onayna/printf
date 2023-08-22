#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1, on error -1.
 */
int _putchar(char c)
{
    return write(1, &c, 1);
}

/**
 * print_binary - prints an unsigned integer in binary format
 * @n: The unsigned integer to print
 */
void print_binary(unsigned int n)
{
    if (n > 1)
        print_binary(n / 2);
    _putchar((n % 2) + '0');
}

/**
 * _printf - simplified printf function
 * @format: format string
 * @...: variadic arguments
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int printed = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            _putchar(*format);
            printed++;
        }
        else
        {
            format++; // Move past '%'
            if (*format == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                print_binary(num);
                printed += 32; // Assuming 32-bit unsigned int
            }
        }
        format++;
    }

    va_end(args);

    return printed;
}

int main(void)
{
    _printf("Binary representation of %b: %b\n", 42, 255);
    return 0;
}
