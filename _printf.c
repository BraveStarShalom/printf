#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - custom Printf function
 * @form: the format string
 * Return: the number of characters Printed
 */

int _printf(const char *form, ...)
{
	int k, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (form == NULL)

		return (-1);
	va_start(list, form);
	for (k = 0; form && form[k] != '\0'; k++)
	{
		if (form[k] != '%')
		{
			buffer[buff_ind++] = form[k];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &form[k], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = get_flags(form, &k);
			width = width_measure(form, &k, list);
			precision = precision_measure(form, &k, list);
			size = get_size(form, &k);
			++k;
			printed = handle_print(form, &k, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
