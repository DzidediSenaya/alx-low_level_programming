#include"main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: where number of bytes is returned
 * @accept : bytes in s
 * Return: the number of bytes in the initial segment of
 * s which consist only of bytes from accept
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int a = 0;
	int i;

	while (*s)
	{
		for (i = 0; accept[i]; i++)
		{
			if (*s == accept[i])
			{
				a++;
				break;
			}

			else if (accept[i + 1] == '\0')
				return (a);
		}

		s++;
	}

	return (a);
}

