#include "main.h"

/**
 * print_number - prints an integer.
 * @n: integer
 * Return: Always 0
 *
 */

void print_number(int n)
{
	long e, num, b, c, exp;

	num = n;
	exp = e =  1;

	if (num < 0)
	{
		num *= -1;
		_putchar('-');
	}

	c = num;
	while (c >= 10)
	{
		e++;
		c /= 10;
	}

	for (b = 1; b < e; b++)
		exp *= 10;

	while (exp > 1)
	{
		_putchar((num / exp) % 10 + '0');
		exp /= 10;
	}
	_putchar(num % 10 + '0');
}
