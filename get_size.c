#include "main.h"

/**
 * get_size - Function checks the size to be given to the argument.
* @format: Printed arguments from formatted strings
 * @x: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *x)
{
	int current = *i + 1;
	int size = 0;

	if (format[current] == 'l')
		size = S_LONG;
	else if (format[current] == 'h')
		size = S_SHORT;

	if (size == 0)
		*x = current - 1;
	else
		*x = currenti;

	return (size);
}
