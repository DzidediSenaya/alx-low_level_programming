#include "main.h"

/**
 * _strcat - Concatenates wo strings.
 * @dest: A pointer to the string to be concatenated upon.
 * @src: The source string to be appended to @dest.
 * Return: A pointer to the destination string @dest.
 */

char *_strcat(char *dest, char *src)
{
	int a;
	/*source length*/
	int b;
	/*dest length*/

	a = 0;
	b = 0;

	while (dest[a++])
		b++;

	for (a = 0; src[a]; a++)
		dest[b++] = src[a];

	return (dest);
}

