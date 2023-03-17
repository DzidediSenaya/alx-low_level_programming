#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if a is a digit, 0 otherwise
 */

int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: the string to check
 * Return:length of string
 */

int _strlen(char *s)
{
	int l = 0;

	while (*s++)
		l++;
	return (l);
}


/**
 * positive_mult - multiplies two positive numbers
 * @num1: first positive number
 * @num2: second positve number
 * Return: the product of num1 and num2
 */

char *positive_mult(char *num1, char *num2)
{
	char *prod;
	int a, b, c, d, e, f;

	a = _strlen(num1);
	b = _strlen(num2);
	prod = malloc(c = f = a + b);
	if (!prod)
		printf("Error\n"), exit(98);
	while (c--)
		prod[c] = 0;

	for (a--; a >= 0; a--)
	{
		if (!_isdigit(num1[a]))
		{
			free(prod);
			printf("Error\n"), exit(98);
		}
		c = num1[a] - '0';
		e = 0;

		for (b = _strlen(num2) - 1; b >= 0; b--)
		{
			if (!_isdigit(num2[b]))
			{
				free(prod);
				printf("Error\n"), exit(98);
			}
			d = num2[b] - '0';

			e += prod[a + b + 1] + (c * d);
			prod[a + b + 1] = e % 10;

			e /= 10;
		}
		if (e)
			prod[a + b + 1] += e;
	}
	return (prod);
}

/**
 * main - multiply two positive number strings
 * @argc: the number of arguments
 * @argv: the argument vector
 * Return: Always 0 on success.
 */

int main(int argc, char **argv)
{
	char *prod;
	int c, e, f;

	if (argc != 3)
		printf("Error\n"), exit(98);

	f = _strlen(argv[1]) + _strlen(argv[2]);
	prod = positive_mult(argv[1], argv[2]);
	e = 0;
	c = 0;
	while (e < f)
	{
		if (prod[e])
			c = 1;
		if (c)
			_putchar(prod[e] + '0');
		e++;
	}
	if (!c)
		_putchar('0');
	_putchar('\n');
	free(prod);
	return (0);
}
