#include "main.h"

/**
 * _memcpy - a function that copies memory area.
 * @n: bytes to be copied
 * @src:memory area to copy from
 * @dest: memory area to copy to
 * Return: dest
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
