#include "main.h"

#include <stdio.h>
/**
 * print_diagsums - prints the sum of the two diagonals
 * of a square matrix of integers
 * @a: int array
 * @size: array size
 */
void print_diagsums(int *a, int size)
{
	int y, b, c, d, e;

	c = 0;
	d = 0;
	e = 0;
	for (y = 0; y < size; y++)
		for (b = 0; b < size; b++)
		{
			(y == b) ? d += a[c] : 0;
			(y + b == size - 1) ? e += a[c] : 0;
			c++;
		}
	printf("%i, %i\n", d, e);
}
