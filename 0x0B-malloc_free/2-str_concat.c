#include "main.h"
#include <stdlib.h>

/**
 * str_concat - Concatenates two strings
 * @s1: first string
 * @s2: second string
 * Return: NULL If concatenation fails
 * else, a pointer the newly-allocated space in memory
 * containing the concatenated strings
 */

char *str_concat(char *s1, char *s2)
{
	char *string_concat;
	int i, concat_index = 0, j = 0;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	for (i = 0; s1[i] || s2[i]; i++)
		j++;

	string_concat = malloc(sizeof(char) * j);

	if (string_concat == NULL)
		return (NULL);

	for (i = 0; s1[i]; i++)
		string_concat[concat_index++] = s1[i];

	for (i = 0; s2[i]; i++)
		string_concat[concat_index++] = s2[i];

	return (string_concat);
}
