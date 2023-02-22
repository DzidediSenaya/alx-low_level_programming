#include <stdio.h>
/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 *
 * Return: void
 */

int main(void)
{
	unsigned int a, b, c, d, e;

	a = 1;
	b = 2;
	c = 3;
	d = 2;
	for (e = 2; e <= 32; e++)
	{
		if (c % 2 == 0)
			d = d + c;
		a = b;
		b = c;
		c = a + b;
	}
	printf("%u\n", d);
	return (0);
}
