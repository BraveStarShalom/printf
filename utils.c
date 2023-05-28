#include "main.h"

/**
 * isPrintable - Evaluates if a char is printable
 * @ar: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int isPrintable(char ar)
{
	if (ar >= 32 && ar < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @id: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int id)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[id++] = '\\';
	buffer[id++] = 'x';

	buffer[id++] = map_to[ascii_code / 16];
	buffer[id] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit
 * @ar: Char to be evaluated
 *
 * Return: 1 if ar is a digit, 0 otherwise
 */
int is_digit(char ar)
{
	if (ar >= '0' && ar <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Casts a number to the specified size
 * @numb: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of numb
 */
long int convert_size_number(long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((short)numb);

	return ((int)numb);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @numb: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of numb
 */
long int convert_size_unsgnd(unsigned long int numb, int size)
{
	if (size == S_LONG)
		return (numb);
	else if (size == S_SHORT)
		return ((unsigned short)numb);

	return ((unsigned int)numb);
}
