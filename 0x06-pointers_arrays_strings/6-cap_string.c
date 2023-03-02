#include "main.h"

/**
 * cap_string - capitalizes all words of a string
 * @y: string
 * Return: capitalized string
 */

char *cap_string(char *y)
{
	int i = 0;
	int j;
	char symbols[] = " \n\t,;.!?\"(){}";


	if (y[0] >= 'a' && y[0] <= 'z')
		y[0] -= 32;

	for (; y[i] != '\0'; i++)
	{
		for (j = 0; j < 14; j++)
		{
			if (y[i] == symbols[j])
			{
				if (y[i + 1] >= 'a' && y[i + 1] <= 'z')
					y[i + 1] -= 32;
			}
		}
	}

	return (y);
}
