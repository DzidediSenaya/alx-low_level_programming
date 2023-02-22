#include<stdio.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers
 *
 * Return: void.
 */
int main(void)
{
	unsigned long int a, a0, a1, b, b0, b1, c, c0, c1, d, e;

	a = 1;
	b = 2;
	c = a + b;

	printf("%lu, ", a);
	printf("%lu, ", b);
	for (d = 3; d < 89; d++)
	{
		printf("%lu, ", c);
		a = b;
		b = c;
		c = a + b;
	}
	b0 = b / 1000000000;
	b1 = b % 1000000000;
	c0 = c / 1000000000;
	c1 = c % 1000000000;
	for (e = 89; e < 98; e++)
	{
		printf("%lu%lu, ", c0, c1);
		a0 = b0;
		a1 = b1;
		b0 = c0;
		b1 = c1;
		c0 = a0 + b0 + ((a1 + b1) / 1000000000);
		c1 = (a1 + b1) % 1000000000;
	}
printf("%lu%lu\n", c0, c1);
	return (0);
}
