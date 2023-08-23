#include "main.h"

/**
 * get_width - Function calculates the width for printing
* @format: Printed arguments from formatted strings
 * @i: List of arguments to be printed.
 * @list: List of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *i, va_list list)
{
	int current;
	int width = 0;

	for (current = *i + 1; format[current] != '\0'; current++)
	{
		if (is_digit(format[current]))
		{
			width *= 10;
			width += format[current] - '0';
		}
		else if (format[current] == '*')
		{
			current++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current - 1;

	return (width);
}
