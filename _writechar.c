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
            if (*format == 'd' || *format == 'i')
            {
                int num = va_arg(args, int);
                int num_copy = num;
                int digits = 0;

                if (num < 0)
                {
                    _putchar('-');
                    printed++;
                    num_copy = -num_copy;
                }

                while (num_copy > 0)
                {
                    num_copy /= 10;
                    digits++;
                }

                while (digits > 0)
                {
                    int divisor = 1;
                    int i = digits - 1;

                    while (i > 0)
                    {
                        divisor *= 10;
                        i--;
                    }

                    _putchar((num / divisor) % 10 + '0');
                    printed++;
                    digits--;
                }
            }
        }
        format++;
    }

    va_end(args);

    return printed;
}

int main(void)
{
    _printf("This is an integer: %d\n", 42);
    _printf("Another integer: %i\n", -123);
    return 0;
}
