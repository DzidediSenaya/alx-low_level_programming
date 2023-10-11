#include <stdio.h>
#include "search_algos.h"

/**
 * interpolation_search - Searches for a value in a sorted array using interpolation search.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * @value: The value to search for.
 *
 * Return: Index of the value if found, -1 if not found or on error.
 */
int interpolation_search(int *array, size_t size, int value)
{
 int low = 0;
    int high = (int)size - 1;
    int pos;

    if (array == NULL || size == 0)
        return (-1);

    while (low <= high && value >= array[low] && value <= array[high])
    {
        pos = low + (((double)(high - low) / (array[high] - array[low])) * (value - array[low]));

        printf("Value checked array[%d] = [%d]\n", pos, array[pos]);

        if (array[pos] == value)
            return (pos);

        if (array[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    printf("Value checked array[%d] is out of range\n", pos);

    return (-1);
}
