#include "function_pointers.h"

/**
 * int_index - searches for an integer
 * @array: array to search through
 * @size: number of elements in the array
 * @cmp: pointer to the function to be used to compare values
 * Return: the index of the first element for which the cmp function
 * does not return
 * -1 if no element matches
 * -1 if size <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int a;
	int (*p)(int);

	p = cmp;

	if (size <= 0)
		return (-1);
	if (!array || !cmp)
		return (-1);

	for (a = 0; a < size; a++)
	{
		if (p(array[a]) && array[a] != 0)
			break;
		if (a == size - 1)
			return (-1);
	}
	return (a);
}
