#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - Returns a pointer to a 2-dimensional array of
 * integers with each element initalized to 0.
 * @width: The width of the 2-dimensional array.
 * @height: The height of the 2-dimensional array.
 * Return: NULL on failure
 * NULL If width or height is 0 or negative
 */

int **alloc_grid(int width, int height)
{
	int **two_dim;
	int height_index, width_index;

	if (width <= 0 || height <= 0)
		return (NULL);

	two_dim = malloc(sizeof(int *) * height);

	if (two_dim == NULL)
		return (NULL);

	for (height_index = 0; height_index < height; height_index++)
	{
		two_dim[height_index] = malloc(sizeof(int) * width);

		if (two_dim[height_index] == NULL)
		{
			for (; height_index >= 0; height_index--)
				free(two_dim[height_index]);

			free(two_dim);
			return (NULL);
		}
	}

	for (height_index = 0; height_index < height; height_index++)
	{
		for (width_index = 0; width_index < width; width_index++)
			two_dim[height_index][width_index] = 0;
	}

	return (two_dim);
}
