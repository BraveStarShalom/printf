#include "main.h"

/**
 * precision_measure - calculates precision for printing
 * @format: formatted string for printing arguments
 * @i: arguments to be printed.
 * @list: arguments
 * Return: Precision.
 */
int precision_measure(const char *format, int *i, va_list list)
{
	int p = *i + 1;
	int precision = -1;

	if (format[p] != '.')
		return (precision);

	precision = 0;

	for (p += 1; format[p] != '\0'; p++)
	{
		if (is_digit(format[p]))
		{
			precision *= 10;
			precision += format[p] - '0';
		}
		else if (format[p] == '*')
		{
			p++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = p - 1;

	return (precision);
}
