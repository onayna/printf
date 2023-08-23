#include "main.h"

/**
 * get_flags - Function calculates for all active flags
 * @format: Printed arguments from formatted strings
 * @a: Parameter to be taken into consideration
 * Return: All active flags
 */

int get_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int x, current, flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (current = *a + 1; format[current] != '\0'; current++)
	{
		for (x = 0; FLAGS_CHAR[x] != '\0'; x++)
			if (format[current] == FLAGS_CHAR[x])
			{
				flags |= FLAGS_ARR[x];
				break;
			}

		if (FLAGS_CHAR[x] == 0)
			break;
	}

	*a = current - 1;

	return (flags);
}

