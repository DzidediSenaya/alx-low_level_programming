#include "main.h"

/**
 * print_number - prints an integer.
 * @n: integer
 * Return: Always 0
 *
 */

void print_number(int n)
{
	long a;
	int b;
	long c;

	c = n;


	if (c < 0)
	{
		c *= -1;
		_putchar('-');
	}

	a = 1;
	b = 1;

	while (b)
	{
		if (c / (a * 10) > 0)
			a *= 10;
		else
			b = 0;
	}

	while (c >= 0)
	{
		if (a == 1)
		{
			_putchar(c % 10 + '0');
			c = -1;
		}
		else
		{
			_putchar((c / a % 10) + '0');
			a /= 10;
		}
	}
}
