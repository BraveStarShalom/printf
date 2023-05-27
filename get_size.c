#include "main.h"

/**
 * get_size - Calculates the size to cast argument
 * @format: Formatted string to print the arguments
 * @t: arguments listed to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *t)
{
	int curr_t = *t + 1;
	int size = 0;

	if (format[curr_t] == 'l')
		size = S_LONG;
	else if (format[curr_t] == 'w')
		size = S_SHORT;

	if (size == 0)
		*t = curr_t - 1;
	else
		*t = curr_t;

	return (size);
}
