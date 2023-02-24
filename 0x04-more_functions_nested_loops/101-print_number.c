#include "main.h"

/**
 * print_number - prints an integer.
 * @n: integer
 * Return: Always 0
 *
 */

void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		print_unsigned_int(-(unsigned int)n);
	}
	else
		print_unsigned_int(n);
	
	else if (n / 10 != 0)
	{
		print_unsigned_int(n / 10);
	}
	_putchar((n % 10) + '0');
}
