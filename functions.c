#include "main.h"

/* PRINTING CHARACTERS */

/**
 * print_character - Function prints a character
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checking for number of active flags
 * @width: Checking for specified width
 * @precision: Checking for specified precision
 * @size: Checking for specified size
 * Return: Exact characters put in system
 */
int print_character(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(args, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}

/* PRINTING STRINGS */
/**
 * print_string - Function prints a string
 * @args: List a of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for number of active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Exact characters (string) put in the system
 */

int print_string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, num;
	char *str = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (num = width - length; num > 0; num--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (num = width - length; num > 0; num--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/* PRINTING THE PERCENT SIGN (%) */
/**
 * print_percent - Function prints the percent sign (%)
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for number of active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: The percent sign put in the system
 */

int print_percent(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/* PRINTING INTEGER */
/**
 * print_integer - Function prints an integer
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags: Checks for active flags
 * @width: Checks for specified width.
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Exact integer put in the system
 */

int print_integer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int num = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int rem;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[num--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	rem = (unsigned long int)n;

	if (n < 0)
	{
		rem = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (rem > 0)
	{
		buffer[num--] = (rem % 10) + '0';
		rem /= 10;
	}

	num++;

	return (write_number(is_negative, num, buffer, flags, width,
				precision, size));
}

/* PRINTING BINARY */
/**
 * print_binary - Function prints an unsigned number
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags: Calculates active flags
 * @width: Checking for specified width.
 * @precision: Checking for specified precision
 * @size: Checking for specified size
 * Return: Exact character of binary put in the system.
 */

int print_binary(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int num, binary, integer, sum;
	unsigned int a[32];
	int c;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(args, unsigned int);
	binary = 2147483648; /* (2 ^ 31) */
	a[0] = num / binary;
	for (integer = 1; integer < 32; integer++)
	{
		binary /= 2;
		a[integer] = (num / binary) % 2;
	}
	for (integer = 0, sum = 0, c = 0; integer < 32; integer++)
	{
		sum += a[integer];
		if (sum || integer == 31)
		{
			char mac = '0' + a[integer];

			write(1, &mac, 1);
			c++;
		}
	}
	return (c);
}
