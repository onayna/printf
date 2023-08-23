#include "main.h"

/* WRITING HANDLER */
/**
 * handle_write_char - Function prints a string
 * @c: Character to be checked
 * @buffer: Array of buffer to handle print
 * @flags: Checks for active flags.
 * @width: Checks for specified width.
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 *
 * Return: Strings
 */

int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int x = 0;
	char padd = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & F_ZERO)
		padd = '0';

	buffer[x++] = c;
	buffer[x] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (x = 0; x < width - 1; x++)
			buffer[BUFF_SIZE - x - 2] = padd;

		if (flags & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - x - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - x - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

/* WRITE NUMBER */
/**
 * write_number - Function prints a string
 * @is_negative: Lista of arguments
 * @index: Types of character.
* @buffer: Array of buffer to handle print
 * @flags: Checks for active flags.
 * @width: Checks for specified width.
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 *
 * Return: Inputted integers
 */

int write_number(int is_negative, int index, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - index - 1;
	char padd = ' ', extra_char = 0;

	UNUSED(size);

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_char = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_char = ' ';

	return (write_num(ind, buffer, flags, width, precision,
		length, padd, extra_char));
}

/**
 * write_num - Function uses a buffer to write a number
 * @index: Index at which the number starts on the buffer
* @buffer: Array of buffer to handle print
 * @flags: Checks for active flags.
 * @width: Checks for specified width.
 * @precision: Checks for specified precision
 * @padd: Character padding
 * @extra_char: Extra character added
 *
 * Return: Printed characterss.
 */

int write_num(int index, char buffer[],
	int flags, int width, int precision,
	int length, char padd, char extra_char)
{
	int k, padd_start = 1;

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0'
			&& width == 0)
		return (0);
	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		buffer[index] = padd = ' ';
	if (precision > 0 && prec < length)
		padd = ' ';
	while (precision > length)
		buffer[--index] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (k = 1; k < width - length + 1; k++)
			buffer[k] = padd;
		buffer[i] = '\0';
		/* Assigning an extra character to the left side of the buffer */
		if (flags & F_MINUS && padd == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[index], length) + write(1, &buffer[1], k - 1));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			if (extra_char)
				buffer[--index] = extra_char;
			return (write(1, &buffer[1], k - 1) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_char)
				buffer[--padd_start] = extra_char;
			return (write(1, &buffer[padd_start], k - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start)));
		}
	}
	if (extra_char)
		buffer[--index] = extra_char;
	return (write(1, &buffer[index], length));
}

/**
 * write_unsigned- Writes an unsigned number
 * @is_negative: Number indicating if the num is negative
 * @index: Index at which the number starts on the buffer
* @buffer: Array of buffer to handle print
 * @flags: Checks for active flags.
 * @width: Checks for specified width.
 * @precision: Checks for specified precision
 * @size: Checks for specified size
 *
 * Return: Number of written characters.
 */

int write_unsigned(int is_negative, int index,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, x = 0;
	char padd = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';

	while (precision > length)
	{
		buffer[--index] = '0';
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)
	{
		for (x = 0; x < width - length; x++)
			buffer[x] = padd;

		buffer[x] = '\0';

		if (flags & F_MINUS)
		{
			return (write(1, &buffer[index], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], x) + write(1, &buffer[index], length));
		}
	}

	return (write(1, &buffer[index], length));
}

/**
 * write_pointer - Function writes a memory address
 * @buffer: Array of characters to handle print
 * @index: Index at which the number starts on the buffer
 * @length: Character length
 * @width: Checks for specified width
 * @flags: Checks for specified flags
 * @padd: Padding represented by the character
 * @extra_c: Extra character
 * @padd_start: Initial number indicating when padding was started
 *
 * Return: Characters
 */
int write_pointer(char buffer[], int index, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int y;

	if (width > length)
	{
		for (y = 3; y < width - length + 3; y++)
			buffer[x] = padd;
		buffer[y] = '\0';
		if (flags & F_MINUS && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[index], length) + write(1, &buffer[3], y - 3));
		}
		else if (!(flags & F_MINUS) && padd == ' ')
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_c)
				buffer[--index] = extra_c;
			return (write(1, &buffer[3], y - 3) + write(1, &buffer[index], length));
		}
		else if (!(flags & F_MINUS) && padd == '0')
		{
			if (extra_c)
				buffer[--padd_start] = extra_c;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], y - padd_start) +
				write(1, &buffer[index], length - (1 - padd_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_c)
		buffer[--index] = extra_c;
	return (write(1, &buffer[index], BUFF_SIZE - ind - 1));
}
