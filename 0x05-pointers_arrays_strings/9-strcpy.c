#include "main.h"

/**
  * _strcpy - copies the string pointed to by src
  * to the buffer pointed to by dest
  * @dest: destination value
  * @src: source value
  *
  * Return: the pointer to dest
  */

char *_strcpy(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}

	dest[a++] = '\0';

	return (dest);
}
