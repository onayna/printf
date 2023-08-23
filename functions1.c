#include "main.h"

/* PRINTING UNSIGNED NUMBER */
/**
 * print_unsigned - Function prints an unsigned number
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Exact unsigned integer
 */

int print_unsigned(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINTING UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - Function prints unsigned number in octal notation
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @width: Check for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Exact number in octal format
 */
int print_octal(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{

	int a = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[a--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';

	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/* PRINTING UNSIGNED NUMBER IN HEXADECIMAL */
/**
 * print_hexadec - Function prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checking for active flags
 * @width: Checking for specified width
 * @precision: Checking for specified precision
 * @size: Checking for specified size
 * Return: Exact unsigned number
 */

int print_hexadec(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* PRINTING UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - Function prints an unsigned number in
 * upper hexadecimal notation
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Unsigned number in hexadecimal format
 */

int print_hexa_upper(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* PRINTING HEXX NUMBER IN LOWER OR UPPER */
/**
 * print_hexa - Function prints a hexadecimal number in lower or upper
 * @args: List of arguments
 * @map_to: A number with which the array is mapped to
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @flag_check: Checks for active flags also
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Number of chars printed
 */

int print_hexa(va_list args, char map_to[], char buffer[],
	int flags, char flag_check, int width, int precision, int size)
{
	int mac = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[mac--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[mac--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[mac--] = flag_check;
		buffer[mac--] = '0';
	}

	mac++;

	return (write_unsgnd(0, mac, buffer, flags, width, precision, size));
}
