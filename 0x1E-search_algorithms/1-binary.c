#include <stdio.h>
#include "search_algos.h"

/**
 * binary_search - Searches for a value in a sorted array using binary search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index of the value if found, -1 if not found or on error.
 */
int binary_search(int *array, size_t size, int value)
{
int left, right, mid, i;
    
if (array == NULL || size == 0)
return (-1);
    
left = 0;
right = (int)size - 1;
    
while (left <= right)
{
mid = (left + right) / 2;

printf("Searching in array: ");
for (i = left; i <= right; i++)
{
printf("%d", array[i]);
if (i < right)
printf(", ");
else
printf("\n");
}

if (array[mid] == value)
return (mid);
else if (array[mid] < value)
left = mid + 1;
else
right = mid - 1;
}

return (-1);  /* Value not found */
}
