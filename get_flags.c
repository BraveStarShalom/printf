#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @r: parameter to be taken into account
 * Return: Flags:
 */
int get_flags(const char *format, int *r)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int q, curr_r;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_r = *r + 1; format[curr_r] != '\0'; curr_r++)
	{
		for (q = 0; FLAGS_CH[q] != '\0'; q++)
			if (format[curr_r] == FLAGS_CH[q])
			{
				flags |= FLAGS_ARR[q];
				break;
			}

		if (FLAGS_CH[q] == 0)
			break;
	}

	*r = curr_r - 1;

	return (flags);
}
