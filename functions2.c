#include "main.h"

/* PRINT POINTER */
/**
 * print_pointer - Function prints the value of a pointer variable
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Returns a pointer
 */

int print_pointer(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_char = 0, padd = ' ';
	int index = BUFF_SIZE - 2, length = 2, padd_start = 1;
	/* For '0x' length=2, */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_addrs > 0)
	{
		buffer[index--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_char = '+', length++;
	else if (flags & F_SPACE)
		extra_char = ' ', length++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_char, padd_start));
}

/* PRINT NON PRINTABLE */
/**
 * print_non_printable - Function prints ascii codes in hexa of
 * chars not printable
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags:  Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Always 0
 */

int print_non_printable(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int num = 0, i = 0;
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[num] != '\0')
	{
		if (is_printable(str[num]))
			buffer[num + i] = str[num];
		else
			offset += append_hexa_code(str[num], buffer, num + i);

		num++;
	}

	buffer[num + i] = '\0';

	return (write(1, buffer, num + i));
}

/* PRINT REVERSE */
/**
 * print_reverse - Function prints a string in reverse
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags: Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: Reversed string
 */

int print_reverse(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int character, rev = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (character = 0; str[character]; character++)
		;

	for (character = character - 1; character >= 0; character--)
	{
		char z = str[character];

		write(1, &z, 1);
		rev++;
	}
	return (rev);
}
/* PRINT A STRING IN ROT13 */
/**
 * print_rot13string - Function prints a string in rot13.
 * @args: List of arguments
 * @buffer: Handling what is printed with buffer array
 * @flags: Checks for active flags
 * @width: Checks for specified width
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 * Return: ROT13 strings
 */

int print_rot13string(va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	char a;
	char *str;
	unsigned int mac, mal;
	int c = 0;
	char input[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char output[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (mac = 0; str[mac]; mac++)
	{
		for (mal = 0; input[mal]; mal++)
		{
			if (input[mal] == str[mac])
			{
				a = output[mal];
				write(1, &a, 1);
				c++;
				break;
			}
		}
		if (!input[mal])
		{
			a = str[mac];
			write(1, &a, 1);
			c++;
		}
	}
	return (c);
}
