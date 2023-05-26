#include "main.h"

/******************** PRINT CHAR ********************/
/**
  * print_char - prints a character
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags:  calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Characters.
  */
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char p = va_arg(types, int);

	return (character_output(c, buffer, flags, width, precision, size));
}

/******************** PRINT STRING ********************/
/**
  * print_string - prints a string
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Strings.
  */
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int l = 0, p;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[l] != '\0')
		l++;

	if (precision >= 0 && precision < l)
		l = precision;

	if (width > l)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], l);
			for (p = width - l; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (p = width - l; p > 0; p--)
				write(1, " ", 1);
			write(1, &s[0], l);
			return (width);
		}
	}

	return (write(1, s, l));
}

/******************** PRINT PERCENTAGE SIGN ********************/
/**
  * print_percent - prints a percentage sign
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: ize identifier
  * Return: Percentage characters.
  */
int print_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/******************** PRINT INTEGER ********************/
/**
  * print_int - prints an integer
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Integers.
  */
int print_int(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int p = BUFF_SIZE - 2;
	int is_ngtv = 0;
	long int q = va_arg(types, long int);
	unsigned long int nq;

	q = convert_size_number(q, size);

	if (q == 0)
		buffer[p--] = '0';

	buffer[BF_SIZE - 1] = '\0';
	nq = (unsigned long int)q;

	if (q < 0)
	{
		nq = (unsigned long int)((-1) * q);
		is_ngtv = 1;
	}

	while (nq > 0)
	{
		buffer[p--] = (nq % 10) + '0';
		nq /= 10;
	}

	p++;

	return (write_number(is_ngtv, p, buffer, flags, width, precision, size));
}

/******************** PRINT BINARY ********************/
/**
  * print_binary - prints an unsigned number
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Number of count.
  */
int print_binary(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	unsigned int p, q, r, sum;
	unsigned int s[32];
	int collate;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	p = va_arg(types, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	s[0] = p / q;
	for (r = 1; r < 32; r++)
	{
		q /= 2;
		s[r] = (p / q) % 2;
	}
	for (r = 0, sum = 0, collate = 0; r < 32; r++)
	{
		sum += s[r];
		if (sum || r == 31)
		{
			char z = '0' + s[r];

			write(1, &z, 1);
			collate++;
		}
	}
	return (collate);
}

