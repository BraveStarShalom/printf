 #include "main.h"

/****************** PRINT POINTER ******************/
/**
  * print_pointer - prints the value of a pointer variable
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Pointer.
  */
int print_pointer(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char extra_c = 0, p = ' ';
	int ind = BUFF_SIZE - 2, l = 2, padd_start = 1; /* l=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *adrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (adrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)adrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		l++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		p = '0';
	if (flags & F_PLUS)
		extra_c = '+', l++;
	else if (flags & F_SPACE)
		extra_c = ' ', l++;

	ind++;

	/*return (write(1, &buffer[p], BUFF_SIZE - p - 1));*/
	return (write_pointer(buffer, ind, l, width,
				flags, p, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
  * print_non_printable - prints ascii codes in hexa of non printable chars
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Number of chars printed.
  */
int print_non_printable(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int p = 0, offSet = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[p] != '\0')
	{
		if (isPrintable(s[p]))
			buffer[p + offSet] = s[p];
		else
			offSet += append_hexa_code(s[p], buffer, p + offSet);

		p++;
	}

	buffer[p + offSet] = '\0';

	return (write(1, buffer, p + offSet));
}

/************************* PRINT REVERSE *************************/
/**
  * print_reverse - prints strings in reverse
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Reverse string.
  */
int print_reverse(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char *s;
	int p, collate = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (p = 0; s[p]; p++)
		;

	for (p = p - 1; p >= 0; p--)
	{
		char z = s[p];

		write(1, &z, 1);
		collate++;
	}
	return (collate);
}

/************************* PRINT A STRING IN ROT13 *************************/
/**
  * print_rot13string - Print a string in rot13
  * @types: arguments
  * @buffer: buffer array to hold print
  * @flags: calculates active flags
  * @width: width
  * @precision: precision identifier
  * @size: size identifier
  * Return: Numbers of chars printed
  */
int print_rot13string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c;
	char *s;
	unsigned int p, q;
	int collate = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (p = 0; s[p]; p++)
	{
		for (q = 0; in[q]; q++)
		{
			if (in[q] == s[p])
			{
				c = out[q];
				write(1, &c, 1);
				collate++;
				break;
			}
		}
		if (!in[q])
		{
			c = s[p];
			write(1, &c, 1);
			collate++;
		}
	}
	return (collate);
}
