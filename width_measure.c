#include "main.h"

/**
 * width_measure - determines appropriate width for printing
 * @format: formatted string used for printing arguments
 * @i: arguments to be printed
 * @list: arguments
 * Return: Width.
 */
int width_measure(const char *format, int *i, va_list list)
{
	int p;
	int width = 0;

	for (p = *i + 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			width *= 10;
			width += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = p - 1;

	return (width);
}
