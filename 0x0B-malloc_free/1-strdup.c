#include "main.h"
#include <stdlib.h>

/**
 * _strdup - Returns a pointer to a newly-allocated space in memory
 * containing a copy of the string given as parameter.
 * @str: The string to be copied
 * Return: NULL if string  == NULL or insufficient memory is available - NULL.
 * else, a pointer to the duplicated string on success
 */

char *_strdup(char *str)
{
	char *copy;
	int i, j = 0;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		j++;

	copy = malloc(sizeof(char) * (j + 1));

	if (copy == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		copy[i] = str[i];

	copy[j] = '\0';

	return (copy);
}
