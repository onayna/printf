#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Function that replicates the actual printf function
 * @format: A pointer to char indicating actual format.
 * Return: Characters printed
 */

int _printf(const char *format, ...)
{
	int num, printed_characters = 0, output = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (num = 0; format && format[num] != '\0'; num++)
	{
		if (format[num] != '%')
		{
			buffer[buff_index++] = format[num];
			if (buff_index == BUFF_SIZE)
				print_buffer(buffer, &buff_index);
			/* write(1, &format[num], 1);*/
			printed_characters++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &num);
			width = get_width(format, &num, list);
			precision = get_precision(format, &num, list);
			size = get_size(format, &num);
			++num;
			output = handle_print(format, &num, list, buffer,
				flags, width, precision, size);
			if (output == -1)
				return (-1);
			printed_characters += output;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_characters);
}

/**
 * print_buffer - Functions prints the contents of a buffer if it exists
 * @buffer: An array of characters
 * @buff_index: Representation of length.
*/

void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
