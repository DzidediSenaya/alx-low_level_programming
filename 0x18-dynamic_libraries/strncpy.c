#include "main.h"

/**
 * _strncpy - copies a string
 * @dest: buffer
 * @src: string to be copied
 * @n: number of bytes
 * Return: a pointer to dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int a = 0;
	/* a is string length for src*/

	int b = 0;
	/*b is string length for dest*/

	while (src[a++])
		b++;

	for (a = 0; src[a] && a < n; a++)
		dest[a] = src[a];

	for (a = b; a < n; a++)
		dest[a] = '\0';

	return (dest);
}

