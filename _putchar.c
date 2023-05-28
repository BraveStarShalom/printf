#include "main.h"
#include <unistd.h>

/**
 * _putchar - prints a character to standard output
 * @c: character
 * Return: Integer for success.
 */


int _putchar(char c)
{
	return (write(1, &c, 1));
}
