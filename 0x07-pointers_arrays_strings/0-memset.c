#include "main.h"
#include <string.h>

/**
 * _memset - This function fills the first n bytes of the
 * memory area pointed to by s with the constant byte b
 * @n: bytes of memory to be filled
 * @s: pointer to n
 * @b: constant byte
 * Return: a pointer to the memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;


	return (s);

}
