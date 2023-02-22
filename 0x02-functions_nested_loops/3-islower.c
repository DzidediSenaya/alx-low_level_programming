#include "main.h"

/**
 *_islower - prints character in lowercase
 *@c: character to be printed.
 *
 * Return: 1 if c it is lowercase or 0 otherwise
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
