#include "main.h"

/**
 * _strncat - Concatenates two strings using at most
 * @dest: destination string
 * @src: The string to be appended
 * @n: The number of bytes from src to be appended to dest
 *
 * Return: A pointer to the resulting string dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int a;
	/*source length*/
	int b;
	/*destination length*/

	a = 0;
	b = 0;

	while (dest[a++])
		b++;

	for (a = 0; src[a] && a < n; a++)
		dest[b++] = src[a];

	return (dest);
}

