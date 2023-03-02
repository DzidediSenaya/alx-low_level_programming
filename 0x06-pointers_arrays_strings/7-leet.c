#include "main.h"

/**
 * leet - Encodes a string to 1337
 * @string: string to be encoded
 * Return: pointer to encoded string
 */

char *leet(char *string)
{
	int i = 0, j;
	char leet[8] = {'O', 'L', '?', 'E', 'A', '?', '?', 'T'};

	while (string[i])
	{
		for (j = 0; j <= 7; j++)
		{
			if (string[i] == leet[j] ||
			    string[i] - 32 == leet[j])
				string[i] = j + '0';
		}

		i++;
	}

	return (string);
}
