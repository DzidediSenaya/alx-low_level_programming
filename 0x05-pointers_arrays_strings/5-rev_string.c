#include "main.h"

/**
  * rev_string - Reverses a string
  * @s: The string to be reversed
  * Return: void
  */

void rev_string(char *s)
{
	char rev = s[0];
	int ctr = 0;
	int a;

	while (s[ctr] != '\0')
		ctr++;
	for (a = 0; a < ctr; a++)
	{
		ctr--;
		rev = s[a];
		s[a] = s[ctr];
		s[ctr] = rev;
	}
}
