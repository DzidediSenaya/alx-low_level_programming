#include "main.h"

/**
 * reverse_array - reverse the content of an array of integers
 *
 * @a: the array to reverse
 * @n: the number of elements in the array
 * Return: nothing
 */

void reverse_array(int *a, int n)
{
	int temp, i;

	for (i = n - 1; i >= n / 2; i--)
	{
		temp = a[n - 1 - i];
		a[n - 1 - i] = a[i];
		a[i] = temp;
	}
}

