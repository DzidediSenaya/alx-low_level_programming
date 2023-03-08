#include "main.h"

/**
 * div_num - checks if a number is divisible
 * @i: number to be checked
 * @j: number to be divided by
 * Return: -0 If the number is divisible by j
 * -1 if the number is not divisible by j
 */

int div_num(int i, int j)
{
	if (i == j)
		return (1);
	else if (i % j == 0)
		return (0);
	return (div_num(i, j + 1));
}

/**
 * is_prime_number - Checks if a number is prime.
 * @n: The number to be checked.
 *
 * Return: If the integer is not prime - 0.
 *         If the number is prime - 1.
 */

int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (div_num(n, 2));
}
