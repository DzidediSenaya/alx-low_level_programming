#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @y: the string to encode
 * Return: the new string
 */

char *rot13(char *y)
{
	int i, j;
	char a[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char b[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; y[i] != '\0'; i++)
	{
		for (j = 0; j < 56; j++)
		{
			if (y[i] == a[j])
			{
				y[i] = b[j];
				break;
			}
		}
	}

	return (y);
}
