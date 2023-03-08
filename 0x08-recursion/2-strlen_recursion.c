#include "main.h"

/**
 * _strlen_recursion - Returns the length of a string
 * @s: String to be measured
 * Return: Length of the string
 */

int _strlen_recursion(char *s)
{
	int length = 0;

	/*length of string*/

	if (*s)
	{
		length++;
		length += _strlen_recursion(s + 1);
	}

	return (length);
}
