#include "main.h"

/**
 * _palindrome1 - finds string length
 * @str: string
 * @l: string length
 * Return: returns 1 if a string is a palindrome
 * and 0 if not
 */

int _palindrome1(char *str, int l)
{
	if (*str == 0)
		return (l - 1);
	return (_palindrome1(str + 1, l + 1));
}

/**
 * _palindrome2 - checks if string is a palindrome
 * @str: string
 * @l: string length
 * Return: 1 if string is a palindrome
 */

int _palindrome2(char *str, int l)
{
	if (*str != *(str + l))
		return (0);
	else if (*str == 0)
		return (1);
	return (_palindrome2(str + 1, l - 2));
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to evaluate
 * Return: returns 1 if a string is a palindrome
 * and 0 if not
 */

int is_palindrome(char *s)
{
	int j;

	j = _palindrome1(s, 0);
	return (_palindrome2(s, j));
}
