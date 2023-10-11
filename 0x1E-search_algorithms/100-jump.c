#include <stdio.h>
#include <math.h>
#include "search_algos.h"

/**
* jump_search - Searches for a value in a sorted array using jump search.
* @array: Pointer to the first element of the array.
* @size: Number of elements in the array.
* @value: The value to search for.
*
* Return: Index of the value if found, -1 if not found or on error.
*/
int jump_search(int *array, size_t size, int value)
{
int jump = (int)sqrt(size);
int step = jump;
int prev = 0;
int i;

if (array == NULL || size == 0)
return (-1);

printf("Value checked array[%d] = [%d]\n", prev, array[prev]);

while (array[step] < value && step < (int)size)
{
printf("Value checked array[%d] = [%d]\n", step, array[step]);
prev = step;
step += jump;
}

printf("Value found between indexes [%d] and [%d]\n", prev, step);

for (i = prev; i <= step && i < (int)size; i++)
{
printf("Value checked array[%d] = [%d]\n", i, array[i]);
if (array[i] == value)
return (i);
}

return (-1);
}
