#include "main.h"
#include <stddef.h>

/**
 * _strchr - A function that returns first occurrence
 * of a character within a string
 * @c: pointer return destination
 * @s:location of char c
 * Return: s if c is found,
 * else return null
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s != c)
			s++;
		else
			return (s);
	}
	if (c == '\0')
		return (s);

	return (NULL);
}
